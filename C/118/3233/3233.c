#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>
 
typedef long UINT32;
typedef unsigned short int UINT16;
typedef unsigned char BYTE;
 
#define HEADER_SIZE 14
#define INFO_SIZE 40
#define DataSize(bmp) (bmp->width*bmp->height*3)
 
typedef struct BMP {
    BYTE header[HEADER_SIZE];   
    BYTE info[INFO_SIZE];
    // Header
    UINT16 signature; // Magic Number = "BM" = 0x4D42
    UINT32 fileSize; // File size in bytes
    UINT32 hreserved; // unused (=0)
    UINT32 dataOffset; // File offset to Raster Data
    // InfoHeader
    UINT32 size; // Size of InfoHeader =40
    UINT32 width; // Bitmap Width
    UINT16 height; // Bitmap Height
    UINT16 planes; // Number of Planes (=1)
    UINT16 bitsPerPixel; // Bits per Pixel, 1, 4, 8, 16, 24
    UINT32 compression; // Type of Compression, 0 = BI_RGB no compression, 1 = BI_RLE8 8bit RLE encoding, 2 = BI_RLE4 4bit RLE encoding
    UINT32 imageSize; // (compressed) Size of Image, It is valid to set this =0 if Compression = 0
    UINT32 xPixelsPerM; // horizontal resolution: Pixels/meter
    UINT32 yPixelsPerM; // vertical resolution: Pixels/meter
    UINT32 colorsUsed; // Number of actually used colors
    UINT32 colorsImportant; // Number of important colors , 0 = all
    // ColorTable : present only if Info.BitsPerPixel <= 8 colors should be ordered by importance
    BYTE blue; // Blue intensity
    BYTE green; // Green intensity
    BYTE red; // Red intensity
    BYTE creserved; // unused (=0)
    // Raster Data
    BYTE *data;
} BMP;
 
typedef struct Pixel {
    BYTE R;
    BYTE G;
    BYTE B;
} Pixel;
 
#define U16(x)    ((unsigned short) (x))
#define U32(x)    ((int) (x))
#define B2U16(bytes,offset)  (U16(bytes[offset]) | U16(bytes[offset+1]) << 8)
#define B2U32(bytes,offset)  (U32(bytes[offset]) | U32(bytes[offset+1]) << 8 | \
                   U32(bytes[offset+2]) << 16 | U32(bytes[offset+3]) << 24)
 
int bmpLoad(BMP *bmp, char *fileName) {
   FILE *file;
   BYTE header[14];
   BYTE info[40];
 
   if ((file = fopen(fileName, "rb") ) == NULL ) {
      fprintf(stderr, "Error: bmpLoad(), File open fail!\n");
      exit(0);
   }
 
   fread(header, 1, HEADER_SIZE, file);
   fread(info, 1, INFO_SIZE, file);
   memcpy(bmp->header, header, HEADER_SIZE);
   memcpy(bmp->info, info, INFO_SIZE);
   // Header
   bmp->signature = B2U16(header,0); assert(bmp->signature == 0x4D42);
   bmp->fileSize = B2U32(header,2);
   bmp->dataOffset = B2U32(header,10);
   // InfoHeader
   bmp->size = B2U32(info,0); assert(bmp->size==40);
   bmp->width = B2U32(info,4);
   bmp->height = B2U32(info,8);
   bmp->planes = B2U16(info,12); assert(bmp->planes==1);
   bmp->bitsPerPixel = B2U16(info,14); assert(bmp->bitsPerPixel==24);
   bmp->compression = B2U32(info,16);
   bmp->imageSize = B2U32(info,20);
   bmp->xPixelsPerM = B2U32(info,24);
   bmp->yPixelsPerM = B2U32(info,28);
   bmp->colorsUsed = B2U32(info,32);
   bmp->colorsImportant = B2U32(info,36);
   //存放pixel的資料
   bmp->data = malloc(DataSize(bmp));
   fseek(file, bmp->dataOffset, SEEK_SET);
   fread(bmp->data, 1, DataSize(bmp), file);
 
   fclose (file);
}
 
int bmpPrint(BMP *bmp) {
   printf("==== Header ====\n");
   printf("Signature = %04X\n", bmp->signature); // 0x4d42 = BM
   printf("FileSize = %ld \n", bmp->fileSize);
   printf("DataOffset = %ld \n", bmp->dataOffset);
   printf("==== Info ======\n");
   printf("size = %ld \n", bmp->size);
   printf("Width = %ld \n", bmp->width);
   printf("Height = %ld \n", bmp->height);
   printf("Planes = %d \n", bmp->planes);
   printf("BitsPerPixel = %d \n", bmp->bitsPerPixel);
   printf("Compression = %ld \n", bmp->compression);
   printf("ImageSize = %ld \n", bmp->imageSize);
   printf("XpixelsPerM = %ld \n", bmp->xPixelsPerM);
   printf("YpixelsPerM = %ld \n", bmp->yPixelsPerM);
   printf("ColorsUsed = %ld \n", bmp->colorsUsed);
   printf("ColorsImportant = %ld \n", bmp->colorsImportant);
}
 
int LinearEnhance(BMP *bmp, double gamma){
    Pixel *pixel;
    int idx;
    int i,j;
    //使用巢狀迴圈對每個pixel操作
    for (i=0; i<bmp->width; i++)
        for (j=0; j<bmp->height; j++){
            idx = i * bmp->width + j;
            pixel = (Pixel*) &bmp->data[idx * sizeof(Pixel)];
            //加超過255會溢位反黑
            //pixel->R = pixel->R+gamma;
            //pixel->G = pixel->G+gamma;
            //pixel->B = pixel->B+gamma;
 
            //判斷如果相加超過的話就使維持最大值 255
            if(pixel->R+gamma>255)
                pixel->R=255;
            else
                pixel->R = pixel->R+gamma;
 
            if(pixel->G+gamma>255)
                pixel->G=255;
            else
                pixel->G = pixel->G+gamma;
 
            if(pixel->B+gamma>255)
                pixel->B=255;
            else
                pixel->B = pixel->B+gamma;
        }
}
 
int PowerLaw(BMP *bmp, double gamma){
    //請完成此函式  
    Pixel *pixel;
    int idx;
    int i,j;

    //使用巢狀迴圈對每個pixel操作
    for (i=0; i<bmp->width; i++)
        for (j=0; j<bmp->height; j++){
            idx = i * bmp->width + j;
            pixel = (Pixel*) &bmp->data[idx * sizeof(Pixel)];
            //加超過255會溢位反黑
            //pixel->R = pixel->R+gamma;
            //pixel->G = pixel->G+gamma;
            //pixel->B = pixel->B+gamma;
 
            int c = 255;
            pixel->R = (int) c * pow(pixel->R / 255.0, gamma);
            pixel->G = (int) c * pow(pixel->G / 255.0, gamma);
            pixel->B = (int) c * pow(pixel->B / 255.0, gamma);
        } 
}
 
void resultPrint(double gamma){
    //請完成此函式   
    printf("==== Result ======\n");
    if (gamma > 1) {
        printf("<\n<\n");
    } 
    else if (gamma == 1) {
        printf("==\n<\n");
    } 
    else if (gamma > 0.5) {
        printf(">\n<\n");
    } 
    else if (gamma == 0.5) {
        printf(">\n==\n");
    } 
    else {
        printf(">\n>\n");
    } 
}
 
int bmpSave(BMP *bmp, char *fileName) {
    FILE *file;
    if ((file = fopen(fileName, "wb") ) == NULL ) {
        fprintf(stderr, "Error: bmpSave(), File create fail!\n");
        exit(0);
    }
    fwrite(bmp->header, 1, HEADER_SIZE, file);
    fwrite(bmp->info, 1, INFO_SIZE, file);
    fseek(file, bmp->dataOffset, SEEK_SET);
    fwrite(bmp->data, 1, DataSize(bmp), file);
    fclose(file);
}
 
int main(int argc, char *argv[]) {
    BMP bmp;  
    char filename[100];
    float gamma;

    scanf("%s", filename);
    scanf("%f", &gamma);

    // bmpLoad(&bmp, "01.bmp");
    bmpLoad(&bmp, filename);
    bmpPrint(&bmp);
 
    // LinearEnhance(&bmp, 150);
    PowerLaw(&bmp, gamma);
    
    strcpy( filename + strlen(filename) - 4, "-new.bmp");
    bmpSave(&bmp, filename);
 
    resultPrint(gamma);
 
    return 0;
}
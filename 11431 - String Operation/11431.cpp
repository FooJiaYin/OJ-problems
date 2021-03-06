#include "function.h"
#include "string.h"

typedef void (*FUNC)(Str &s1,Str &s2);

const int OPnum=5;
typedef struct _OPmap{
    const char *op;
    FUNC fp;
}OPmap;

void func_si(Str &s1,Str &s2){
    s1.strSwap(s2).strInsert(s2);
}

void func_is(Str &s1,Str &s2){
    s1.strInsert(s2).strSwap(s2);
}

void func_s(Str &s1,Str &s2){
    s1.strSwap(s2);
}

void func_i(Str &s1,Str &s2){
    s1.strInsert(s2);
}

void func_t(Str &s1,Str &s2){
    if(s1==s2){
        s1.strInsert(s2);
    }else{
        s1.strSwap(s2);
    }
}

OPmap MAP[OPnum]={{"si",func_si},{"is",func_is},{"s",func_s},{"i",func_i},{"t",func_t}};

void operate(char *op,Str &s1,Str &s2){
    for(int i=0;i<OPnum;i++)
        if(strcmp(MAP[i].op,op)==0){
            MAP[i].fp(s1,s2);
            break;
        }
}

int main() {

	int N;
	char input[100];

	int index=0;
	Str *s[100];

	cin>>N;
    for(int i=0;i<N;i++){
    	cin>>input;
    	s[index++]=new Str(input);
    }

    char op[3];//"si" || "is" || "s" || "i" || "t" || "e"
    while(1){
    	cin>>op;
    	if(op[0]=='e')break;

    	int idx1,idx2;
    	cin>>idx1;
    	cin>>idx2;

    	operate(op,*s[idx1],*s[idx2]);
	}

	for(int i=0;i<N;i++){
        s[i]->strPrint();
        delete s[i];
	}

	return 0;
}



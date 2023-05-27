#include <string.h>
#include "function.h"

PalindromeChecker::PalindromeChecker(): word{} {}
PalindromeChecker::PalindromeChecker(const char* str) {
    strcpy(word, str);
}
PalindromeChecker& PalindromeChecker::operator=(const PalindromeChecker& p){
    strcpy(word, p.word);
}
void PalindromeChecker::reverse(){
    PalindromeChecker temp;
    int len = strlen(word);
    for(int i=0; i<len; i++){
        temp.word[i] = word[len-i-1];
    }
    *this = temp;
}
bool operator== (PalindromeChecker &p1, PalindromeChecker &p2){
    return !strcmp(p1.word, p2.word);
}
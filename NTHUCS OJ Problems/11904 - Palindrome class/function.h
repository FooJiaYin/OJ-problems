// function.h
#include <iostream>
#include <string>

using namespace std;

class PalindromeChecker
{
private:
    static const int MAXWORDLENTH=100001;
    char word[MAXWORDLENTH];//store the input string
    
public:
    
    PalindromeChecker();
    PalindromeChecker(const char*);
    PalindromeChecker& operator=(const PalindromeChecker& p);
    void reverse();
    friend bool operator== (PalindromeChecker &p1, PalindromeChecker &p2);

};
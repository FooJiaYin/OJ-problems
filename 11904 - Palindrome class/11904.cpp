// main.cpp
#include <iostream>
#include "function.h"

using namespace std;

int main()
{

    char word[100001];
    while(cin >> word){

    	PalindromeChecker p1(word);
        PalindromeChecker p2;

        p2 = p1;

        p2.reverse();

        if(p1==p2)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
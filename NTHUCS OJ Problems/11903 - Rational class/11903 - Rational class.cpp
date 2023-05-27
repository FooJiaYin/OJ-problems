#include <iostream>
#include <algorithm>
#include "function.h"

using namespace std;

Rational::Rational( int n, int d ){
    numerator = n;
    denominator = d;
    reduce();
}
Rational Rational::addition( const Rational & rhs ) const {
    Rational ans(numerator*rhs.denominator+rhs.numerator*denominator, denominator*rhs.denominator);
    ans.reduce();
    return ans;
}
Rational Rational::subtraction( const Rational & rhs) const {
    Rational ans(numerator*rhs.denominator-rhs.numerator*denominator, denominator*rhs.denominator);
    ans.reduce();
    return ans;
}
Rational Rational::multiplication( const Rational & rhs) const {
    Rational ans(numerator*rhs.numerator, denominator*rhs.denominator);
    ans.reduce();
    return ans;
}
Rational Rational::division( const Rational & rhs) const {
    Rational ans(numerator*rhs.denominator, rhs.numerator*denominator);
    ans.reduce();
    return ans;
}
void Rational::printRational () const{
    cout << numerator << "/" << denominator;
}

int gcd(int a, int b) {
    if(b==0) return a;
    else return gcd(b, a%b);
}

void Rational::reduce() {
    //if(denominator==0) return;
    bool negative = (numerator*denominator <0);
    if(numerator<0) numerator = -numerator;
    if(denominator<0) denominator = -denominator;
    int g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;
    if(negative)
        numerator = -numerator;
}

#include <iostream>
#include "function.h"
using namespace std;

Polynomial::Polynomial() : greatestPower{0}, coefficients{} {};
Polynomial::Polynomial(const int gp , const int co[51]) {
    for(int i=0; i<=101; i++)
        coefficients[i] = (i<=gp)? co[i] : 0;
    greatestPower = gp;
}

Polynomial Polynomial::add( const Polynomial b) const {
    Polynomial ans;
    ans.greatestPower = (greatestPower > b.greatestPower)? greatestPower : b.greatestPower;

    for(int i=0; i<=ans.greatestPower; i++) {
        ans.coefficients[i] = coefficients[i] + b.coefficients[i];
    }
    return ans;
}

Polynomial Polynomial::subtract( const Polynomial b) const {
    Polynomial ans;
    ans.greatestPower = (greatestPower > b.greatestPower)? greatestPower : b.greatestPower;

    for(int i=0; i<=ans.greatestPower; i++) {
        ans.coefficients[i] = coefficients[i] - b.coefficients[i];
    }
    return ans;
}

Polynomial Polynomial::multiplication( const Polynomial b) const {
    Polynomial ans;
    ans.greatestPower = greatestPower + b.greatestPower;

    for(int i=0; i<=greatestPower; i++) {
        for(int j=0; j<=b.greatestPower; j++) {
            ans.coefficients[i+j] += coefficients[i] * b.coefficients[j];
        }
    }
    return ans;
}

void Polynomial::output() const {
    for(int i=greatestPower; i>0; i--){
        cout << coefficients[i] << " ";
    }
    cout << coefficients[0] << endl;
}

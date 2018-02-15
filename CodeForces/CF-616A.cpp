#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); // this will make cin cout faster
    // and if u use it, u cannot use scanf or printf, only cin cout :D
    string number1, number2;
    cin >> number1 >> number2;
    // leading zero bad deya mane ki?
    /// 00000023401 ei number ar 23401 same
    /// taileetake string hishebe niye bam dik theke loop chalano
    /// lagbe jotokkhon NONzero digit pacchi na, ekbar nonzero paile bakita
    /// shob niye nibo
    string a, b;
    for(int i = 0; i < number1.size(); i++) {
        if(number1[i] != '0') {
            for(int j = i; j < number1.size(); j++) {
                a += number1[j];
            }
            break;
        }
    }
    for(int i = 0; i < number2.size(); i++) {
        if(number2[i] != '0') {
            for(int j = i; j < number2.size(); j++) {
                b += number2[j];
            }
            break;
        }
    }

    cout << a << ' ' << b << endl;
    if(a == b) cout << '=' << endl;
    else if(a > b) cout << '>' << endl;
    else cout << '<' << endl;

    return 0;
}

/*
a = 123 b = 1234
b boro karon b te digit beshi a er cheye
a = 12 b = 13
b boro karon digit shonkha shoman holeo b er shesh digit ta
a er shesh digit er cheye boro
a = 77 b = 77
a ar b shoman karon tara ekdom same :v
a = 12432 b = 12532
b boro karon digit sonkha shoman holeo b er 3rd digit a er 3rd digit er
cheye boro
*/
//porchi :D onek moja lagtese . :v

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

string digits[60];

void createArr(){
    digits[0] = "zero";
    digits[1] = "one";
    digits[2] = "two";
    digits[3] = "three";
    digits[4] = "four";
    digits[5] = "five";
    digits[6] = "six";
    digits[7] = "seven";
    digits[8] = "eight";
    digits[9] = "nine";
    digits[10] = "ten";
    digits[11] = "eleven";
    digits[12] = "twelve";
    digits[13] = "thirteen";
    digits[14] = "fourteen";
    digits[15] = "quarter";
    digits[16] = "sixteen";
    digits[17] = "seventeen";
    digits[18] = "eighteen";
    digits[19] = "nineteen";
    digits[20] = "twenty";
    digits[21] = "twenty one";
    digits[22] = "twenty two";
    digits[23] = "twenty three";
    digits[24] = "twenty four";
    digits[25] = "twenty five";
    digits[26] = "twenty six";
    digits[27] = "twenty seven";
    digits[28] = "twenty eight";
    digits[29] = "twenty nine";
    digits[30] = "half";
}
// Complete the timeInWords function below.
void timeInWords(int h, int m) {
    
    //for 00
    if (m == 0)
        cout << digits[h] << " o' clock" << endl;
    else if(m<=30) {
        if (m == 1){
            cout << digits[m] << " minute past " << digits[h] << endl;
        }
        else if (m == 15 || m == 30){
            cout << digits[m] << " past " << digits[h] << endl;
        }
        else{
            cout << digits[m] << " minutes past " << digits[h] << endl;
        }
    }
    else{
        if (m == 45){
            cout << digits[60 - m] << " to " << digits[h+1] << endl;
        }
        else{
            cout << digits[60 - m] << " minutes to " << digits[h+1] << endl;
        }
    }

}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    createArr();
    int h,m;
    cin >> h >> m;
    timeInWords(h,m);
    return 0;
}

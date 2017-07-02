#include<iostream>
void print(int a);
using namespace std;

int main(){
    string hudai;
    int tcase,amplitude,frequency;
    cin >> tcase;
    getline(cin, hudai);
    cin >> amplitude;
    cin >> frequency;
    cout << endl;

    if(amplitude > 9)
        amplitude = 9;

    for(int i=0;i<frequency;i++) {
        int j;
        for(j=1;j<=amplitude;j++) {
            print(j);
            cout << endl;
        }

        for(j=amplitude-1;j>0;j--) {
            print(j);
            cout << endl;
        }

        cout << endl;
    }

    return 0;
}

void print(int a) {
    for(int i=0; i < a; i++) {
        cout << a;
    }

}

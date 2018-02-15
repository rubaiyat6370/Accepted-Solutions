#include <iostream>

using namespace std;

int main() {
    //double x = 2.23536787457;
    int input;
    double temp = 0.0, diff = 9999.0, div = 0.0;
    cin >> input;

    for(int i=1; i < input ; i = i+1) {
        cout << (i*i) << endl;

        if((i*i) < input && (i+1)*(i+1) > input ) {
            temp = i;
            break;
        }

    }

    while ( diff > 0.0001) {
        div = input/temp ;

        temp = (temp + div)/2;

        diff = ((temp*temp) - input);
        cout << diff << endl ;
    }
    cout << temp << endl;

    return 0;

}

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);

    int a,b;
    cin >> a >> b;

    //c=abs(a-b);

    if(a<b)
    {
        cout << a << " " << (b-a)/2 << endl;
    }
    else if(b<a)
    {
        cout << b << " " << (a-b)/2 << endl;
    }
    else
        cout << a << " " << 0 << endl;

    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int rankNumber;
    cin >> rankNumber;

    int rArray[rankNumber],a,b,sum=0;

    for(int i=1; i<rankNumber; i++)
        cin >> rArray[i];
    cin >> a >> b ;

    for(int i=a; i<b; i++)
    {
        sum= sum + rArray[i];
    }
    cout << sum;

    return 0;
}

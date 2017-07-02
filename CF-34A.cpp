#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    int numberOfSoldier,diff=9999,n1,n2;
    cin >> numberOfSoldier;

    int sholdier[numberOfSoldier];

    for(int i=0;i<numberOfSoldier;i++)
        cin >> sholdier[i];

    for(int i=0;i<numberOfSoldier;i++)
    {
        for(int j=0;j<numberOfSoldier;j++)
        {
            int tempDiff = abs(sholdier[i]-sholdier[j]);
           // cout << "\n" << tempDiff << " ";
            if((tempDiff<diff) && (i!=j) && abs(i-j)==1 || (i==0)&&(j==numberOfSoldier-1))
            {
                diff = tempDiff;
                n1=i+1;
                n2=j+1;
            }
        }
    }
    cout << n1 << " " << n2;
    return 0;
}

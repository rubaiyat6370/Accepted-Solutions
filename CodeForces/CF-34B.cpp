#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int numberOfTv, numberOfCapacitity, sum=0;

    cin >> numberOfTv >> numberOfCapacitity;
    int price[numberOfTv];

    for(int i=0;i<numberOfTv;i++)
        cin >> price[i];
    sort(price,price+numberOfTv);

    for(int i=0;i<numberOfCapacitity;i++)
        if(price[i]<0)
            sum= sum + abs(price[i]);
    cout << sum;
    return 0;
}

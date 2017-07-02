#include <iostream>
#include <algorithm>

using namespace std;

bool myGreater(int a, int b) {
    return a > b;
}
int main()
{
    int driveNumber=0, fileSize=0;
    cin >> driveNumber >> fileSize;
    int driveSize[driveNumber];
    for(int i=0;i<driveNumber;i++)
        cin >> driveSize[i];

    sort(driveSize,driveSize+driveNumber, myGreater);
    int sum=0, i;

    for(i=0;i< driveNumber;i++)
    {
        sum = sum + driveSize[i];
        if(sum >= fileSize) break;

    }
    cout << (i+1);

    return 0;

}



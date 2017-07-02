#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int formNumber,i,sum=0;
    cin >> formNumber;

    int form[formNumber];

    for(int i=0;i<formNumber; i++)
        cin >> form[i];

    //sort(form,form+formNumber);

    //for(int i=0;i<formNumber; i++)
       // cout << form[i];

    for(i=0;i<formNumber;i++)
    {
        for(int k=0;k<formNumber;k++)
        {
            if(i==k) continue;
            sum = form[i]+form[k];
            //cout << " " << sum << " " << i<<" " <<" " << k;
            for(int j=0;j<formNumber;j++)
            {
                if(i==j||j==k) continue;
                if(sum==form[j])
                {
                    cout << j+1 << " " << i+1 << " " << k+1;
                    sum=-1;
                    break;
                }
            }
            if(sum==-1) break;
        }
        if(sum==-1) break;

    }
    if(i==formNumber)
        cout << -1;

    return 0;

}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    long double r;
    long long int l,k,ans=1;
    cin >> l >> r >> k;
    int flag=0;
  // if(ans>=l)
     //   cout << ans << " ";
    while(true)
    {
       // ans = (long long) pow(k,i); // overflow hocche ekhane

        if(ans <= (long long)r && ans>=l)
        {
            cout << ans << " ";
            flag = 1;
        }

        if((long double)ans * k > r) break;// ei line e long double lagto?
        else ans = ans * k; // ekhaneo deta jaite pare but she khetre
        // if er condition edit kore ans <= r lagaite hobe
    }
    if(flag==0)
        cout << -1 ;
    return 0;
}

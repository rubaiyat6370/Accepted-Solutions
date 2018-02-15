#include <iostream>

using namespace std;

int main()
{
     ios_base :: sync_with_stdio(false);

     long long int x,ans=0;

     cin >> x;

     for(int i=5;i>0;i--)
     {
         ans = ans + x/i;
         if((x%i)!=0)
            x = x%i;
         else
         {
             cout << ans;
             break;
         }
     }


    return 0;
}

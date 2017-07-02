#include <iostream>

using namespace std;

int main()
{
    int n,add=0,big=0,minimum=0;
    cin >> n ;
    int nArray[n],cArray[n];

    for(int i=0;i<n;i++)
        cin >> nArray[i];

    for(int i=0;i<n;i++)
    {
        add=1;
        minimum=nArray[i];
        for(int j=i;j<n;j++)
        {

            if(minimum>=nArray[j] && i!=j)
            {
                add++;
                minimum = nArray[j];
               // cout << nArray[i] << " " << nArray[j] << " " << add << endl;
            }

            if(minimum<nArray[j])
            {
               // cArray[i] = add;

                break;
            }
        }

        minimum = nArray[i];
        for(int k=i;k>=0;k--)
        {

            if(minimum >=nArray[k] && i!=k)
            {
                add++;
                minimum = nArray[k];
                //cout << nArray[i] << " " << nArray[k] << " " << add << endl;
            }


            if(minimum<nArray[k] )
            {
                break;
            }
        }
        cArray[i] = add;


    }

    for(int i=0;i<n;i++)
    {
        //cout << cArray[i] << endl;
        if(cArray[i]>big)
            big = cArray[i];
    }
    cout << big << endl;
    return 0;
}

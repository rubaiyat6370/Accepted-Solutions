#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    string input, temp;
    cin >> input;

    vector <bool> output(1001, false);

    int m=0,start=1;


    for(int i=0;i<input.length();i++)
    {
        if(input.at(i)==',')
        {
            int value = atoi(temp.c_str());
            output.at(value) = true;

            temp = "";
        }

        else temp += input.at(i);

        if(i==input.length()-1)
        {
            int value = atoi(temp.c_str());
            output.at(value) = true;
            //cout << output[m] << " "

            //temp = "";
        }
    }

    //sort(output.begin(),output.end());
    int i,j,flag=0;

    for(i=1;i<1001; i++)
    {
        if(output[i]==true)
        {
            for(j=i;j<1001;j++)
            {
                if(output[j]==true) continue;
                else break;
            }

            if(i==j-1)
            {
               if(flag==1)
                  cout << ",";
               flag =1;
               cout << j-1;

            }
            else
            {
                if(flag==1)
                  cout << ",";
                flag =1;
                cout << i << "-"<< j-1 ;

            }
            i=j;

        }



    }
}


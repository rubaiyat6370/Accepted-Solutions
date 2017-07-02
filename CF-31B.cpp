#include <iostream>

using namespace std;

int main()
{
    string input, output,temp1,temp2;
    int m=0,i,j;
    cin >> input;
    //cout << input;

    for(i=0;i<input.length;i++)
    {
        if(input[i]=='@')
        {
            temp2= input[i+1];

            output+=temp1;

            output+='@';
            output+=temp2;
            output+=',';
            temp1="";
            temp2="";
            i++;
        }


        temp1[i]= input[i];
    }
}

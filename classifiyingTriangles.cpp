#include<iostream>
#include<fstream>
#define SIZE 100

using namespace std;

int main() {
    int input[SIZE][SIZE],count1,count2,count3,count4,n;
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            cin >> input[i][j];
        }
    }

    cout << input[8][3] << input[9][3] << input[9][4] << endl;
    count1 = count2 = count3 = count4 = 0;

    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-1; j++) {
            if(input[i][j]==1 && input[i+1][j]==1 && input[i+1][j+1]==1)
               count1++;
            if(input[i][j]==1 && input[i][j+1]==1 && input[i+1][j]==1)
                count2++;
            if(input[i][j]==1 && input[i][j+1]==1 && input[i+1][j+1]==1)
                count3++;
            if(input[i][j+1]==1 && input[i+1][j+1]==1 && input[i+1][j]==1)
                count4++;
        }

        cout << "#" << i+1 << " :" << count1<<count2<<count3<<count4 << endl;
    }

    //cout << "#result: " << count1<<count2<<count3<<count4 << endl;




return 0;
}

void readFile() {
    ifstream myReadFile;
    myReadFile.open("text.txt");
    char output;
    if (myReadFile.is_open()) {
        while (!myReadFile.eof()) {

//            myReadFile.getline();
            myReadFile >> output;
            if (output == '\n') break;
            cout<<output << "new line" << endl;

        }
    }
    myReadFile.close();
}

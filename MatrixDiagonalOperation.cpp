#include<iostream>
#define SIZE 100

using namespace std;

int main() {

    int matrix[SIZE][SIZE],n;
    cin >> n;
    for(int i =0; i< n; i++){
        for(int j=0;j<n; j++) {
            cin >> matrix[i][j];
        }
    }

    /*for(int i=0; i< n; i++) {
        for(int j=i+1; j<n; j++) {
            int temp = matrix[i][j];
            //cout << "before " << matrix[i][j] << " "  << matrix[j][i] << endl;
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;

            //cout << "after " << matrix[i][j] << " " << matrix[j][i] << endl;
        }
    }

    for(int i =0; i< n; i++){
        for(int j=0;j<n; j++) {
            cout << matrix[i][j]<<" ";
        }
        cout << endl;
    }*/

    for(int i=0; i< n; i++) {
        for(int j=0; j<n-i-1; j++) {
            int temp = matrix[i][j];
            //cout << "before " << matrix[i][j] << matrix[n -1 - j][n - 1-i] << endl;
            matrix[i][j] = matrix[n -1 - j][n - 1-i];
            matrix[n -1 - j][n - 1-i] = temp;

            //cout << "before " << matrix[i][j] << matrix[n -1 - j][n - 1-i] << endl;
        }
    }

    for(int i =0; i< n; i++){
        for(int j=0;j<n; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }




    return 0;
}


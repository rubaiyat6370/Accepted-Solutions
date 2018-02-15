#include<iostream>
#define SIZE 100

using namespace std;

int main(){
    int matrix[SIZE][SIZE],n;
    int sum = 0;
    int max = -9999;
    cin >> n;
    for(int i =0; i< n; i++){
        for(int j=0;j<n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    for(int i =0; i< n-2; i++){
        for(int j=0;j<n-2; j++) {
            sum = matrix[i][j] + matrix[i][j+1] + matrix[i][j+2] + matrix[i+2][j] + matrix[i+1][j+1] + matrix[i+2][j+1] + matrix[i+2][j+2];
            
            if (sum > max) {
                max = sum ;
            }
        }
    }
    cout << max ;
    
    return 0;
}
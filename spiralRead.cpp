//
//  main.cpp
//  program
//
//  Created by mumu on 4/19/17.
//  Copyright © 2017 mumu. All rights reserved.
//

#include<iostream>
#define SIZE 100

using namespace std;

int matrix[SIZE][SIZE],n;
bool visited[SIZE][SIZE];

int main(){
    //int matrix[SIZE][SIZE],n;
    //bool visited[SIZE][SIZE];
    int offset[4][2] = {{0,1},
        {1,0},
        {0,-1},
        {-1,0}};

    cin >> n;
    for(int i =0; i< n; i++){
        for(int j=0;j<n; j++) {
            cin >> matrix[i][j];
            visited[i][j] = false;
        }
    }


    int p = 0;
    int q = 0;
    int row = n;
    int col = n;
    //cout << matrix[p][q] << endl;
    //visited[p][q] = true;

    for(int i=0;i<=col/2;i++) {

        //cout << "pos :"<< p << " " << q << endl;
        cout << matrix[p][q] << endl;
        visited[p][q] = true;

        for(int m=0;m<4;m++) {
            int x = offset[m][0];
            int y = offset[m][1];

            for(int j=i;j<row-1;j++) {
                p = p + x ;
                q = q + y ;
                //cout << "pos :"<< p << " " << q << endl;
                if(visited[p][q] == false) {
                    //cout << "pos :"<< p << " " << q << endl;
                    cout << matrix[p][q] << endl;
                    visited[p][q] = true;
                }
            }
        }
        p = i+1;
        q = i+1;
        row --;

    }


    return 0;
}

int * printRight(int x, int y) {
    int i = y;
    int arr[2] = {x,y};
    for(i=y;i<n;i++) {
        if(visited[x][i] == false) {
            cout << matrix[x][i] << endl;
            visited[x][i] = true;
        }
        else {
            arr[0] = x;
            arr[1] = i;
            return arr;
        }

    }
    arr[0] = x;
    arr[1] = i;
    return arr;
}

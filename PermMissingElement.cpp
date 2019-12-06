// you can use includes, for example:
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    int s = A.size();
    if (s==0 || A.front() > 1) return 1;
    if(A.back()==s) return s+1; 

    for(int i=1;i<s+1;i++){
        if(A[i-1]!=i) return i;
    }
    return 1;
}

// [] ->1
// [1] ->2
// [2] ->1
// [1,2] ->3
// [1,3] ->2
// [2,3] ->1

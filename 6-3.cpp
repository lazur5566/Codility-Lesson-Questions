// you can use includes, for example:
#include <algorithm>
#include <limits.h>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if(A.size()<3) return 0;
    sort(A.begin(), A.end());
    for (int i=0; i < A.size()-2; i++){
        if (A[i]>0 && A[i+1] > INT_MAX-A[i]) return 1;
        else if (A[i]<0 && A[i+1] < INT_MIN-A[i]); 
        else if ((A[i]+A[i+1])>A[i+2]) return 1;
    }
    return 0;
}
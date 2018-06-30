// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <math.h>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<bool> peaks(A.size(),0);
    for(int i = 1; i<A.size()-1; ){
        if (A[i]>A[i-1] && A[i]>A[i+1]) {
            peaks[i]=1;
            i+=2;
        }
        else i++;
    }
    vector<int> next_peak_pos(A.size(),0);
    next_peak_pos[A.size()-1] = -1;
    for(int i = A.size()-2; i>=0; i--){
        if (peaks[i]) next_peak_pos[i] = i;
        else next_peak_pos[i] = next_peak_pos[i+1];
    }
    int i = 1;
    int result = 0;
    while(i*(i-1)<=A.size()){
        int pos = 0;
        int num = 0;
        while (pos<A.size() && num<i){
            pos = next_peak_pos[pos];
            if (pos==-1) break;
            num+=1;
            pos+=i;
            
        }
        result = max(result, num);
        i++;
    }
    return result;
    
}
// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<long> sorted_lower_bound(A.size());
    vector<long> sorted_upper_bound(A.size());
    int cnt = 0;
    for (int i=0; i<A.size(); i++){
        sorted_lower_bound[i] = (long)i-(long)A[i];
        sorted_upper_bound[i] = (long)i+(long)A[i];
    }
    sort(sorted_lower_bound.begin(), sorted_lower_bound.end());
    sort(sorted_upper_bound.begin(), sorted_upper_bound.end());
    //int lower_idx=0;
    int j = 0;
    for (int i=0; i<A.size(); i++){ 
        while (j<A.size()&&sorted_upper_bound[i]>=sorted_lower_bound[j]){
                j++;
        }
        cnt+=j; // 1 itself, i disk[i]+r<cur[i]+r
    }
    cnt = (long)cnt - (long)(1+A.size())*A.size()/2; // minus duplicate
    if (cnt>10000000) return -1;
    return cnt;
}
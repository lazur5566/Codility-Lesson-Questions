// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int local_max=A[0];
    int global_max=A[0];
    for (int i = 1; i < A.size() ; i++){
        local_max = max(local_max+A[i], A[i]);
        global_max = max(local_max, global_max);
    }
    //cout << local_max;
    return global_max;
}
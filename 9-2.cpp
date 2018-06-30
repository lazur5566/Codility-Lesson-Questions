// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> end_here_max(A.size(),0);
    vector<int> start_here_max(A.size(),0);
    for(int i = 1; i<A.size()-1 ; i++){
        end_here_max[i] = max(end_here_max[i-1]+A[i], 0); // dont need to pick at least 1 element
    }
    for(int i = A.size()-2; i>0 ; i--){
        start_here_max[i] = max(start_here_max[i+1]+A[i], 0);
    }
    int ans = 0;
    for(int i = 1; i<A.size()-1 ; i++){
        ans = max(ans, end_here_max[i-1]+start_here_max[i+1]);
    }
    return ans;
    
}
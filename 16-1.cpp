// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    int sol = 0;
    int j = 0;
    int i = 0;
    
    //for(int i=0; i<N; ++i){
    while (i<N && j<N){
        while (A[j]<=B[i]){
            j++;
            if (j>=N) break;
        }
        i=j;
        sol++;
    }
    return sol;
}

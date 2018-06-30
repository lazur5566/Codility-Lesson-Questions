// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if (A.size()<=1) return 0;
    int buy  = A[0];
    int cur_profit = 0;
    int max_profit = 0;
    for(int i = 1; i < A.size(); i++){
        if (A[i]>buy) {
            cur_profit = max(A[i]-buy, cur_profit);
            max_profit = max(max_profit, cur_profit);
        }
        else{
            cur_profit = 0;
            buy = A[i];
        }
    }
    return max_profit;
}
// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int calc_block_need(int target_minmax_sum, vector<int> &A){
    int block_no = 1;
    int pre_block_sum = A[0];
    for (int i=1; i<A.size(); ++i){
        if (pre_block_sum+A[i] > target_minmax_sum){
            pre_block_sum = A[i];
            block_no ++;
        }
        else pre_block_sum += A[i];
    }
    return block_no;
}
int solution(int K, int M, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size(); // A[i] <= M
    int result_lower_bound = 0;
    int result_upper_bound = 0;
    for(int i=0; i<N; ++i){
        result_lower_bound = max(result_lower_bound, A[i]);
        result_upper_bound += A[i];
    }
    if (K==1) return result_upper_bound;
    if (K>=N) return result_lower_bound;
    
    //cout << "result_upper_bound= " << result_upper_bound << endl;
    //cout << "result_lower_bound= " << result_lower_bound << endl;
    int ans;
    while (result_lower_bound<=result_upper_bound){
        int mid_minmax_sum = (result_lower_bound+result_upper_bound)/2;
        int block_no_needed = calc_block_need(mid_minmax_sum,A);
        //cout << "for mid_minmax_sum = " << mid_minmax_sum << endl;
        //cout << "block_no_needed = " << block_no_needed << endl;
        if (block_no_needed<=K) { // able to get lower minmax sum 
            result_upper_bound = mid_minmax_sum-1;
            ans = mid_minmax_sum;
        }
        else {
            result_lower_bound = mid_minmax_sum+1;
        }
        //cout << "result_upper_bound = " << result_upper_bound << endl;
        //cout << "result_lower_bound = " << result_lower_bound << endl;
    }
    
    return ans;
}
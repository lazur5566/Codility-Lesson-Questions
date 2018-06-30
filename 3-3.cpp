
#include <math.h>
#include <limits.h>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int sum = 0;
    for (int a:A){
        sum+=a;
    }
    int sum_pre = A[0];
    int sum_post = sum-A[0];
    int cur_diff = abs(sum_post-sum_pre);
    int min_diff = cur_diff;
    for (int P=1; P<A.size()-1; P++){
        sum_pre+=A[P];
        sum_post-=A[P];
        cur_diff = abs(sum_post-sum_pre);
        min_diff = min(min_diff, cur_diff);
    }
    return min_diff;
}
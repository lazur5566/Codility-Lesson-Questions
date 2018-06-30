// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <limits.h>
int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    
    int i = 1;
    int min_ans=INT_MAX ;
    for (; i*i<N; i++){
        if (N%i==0) min_ans = min(min_ans, 2*(i+N/i));
    }
    if (i*i==N) min_ans = min(min_ans, 2*(i+N/i));
    return min_ans;
}
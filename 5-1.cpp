#include <math.h>
int solution(int A, int B, int K) {
    // write your code in C++14 (g++ 6.2.0)
    return (floor((double)B/(double)K)-ceil((double)A/((double)K))+1);
}
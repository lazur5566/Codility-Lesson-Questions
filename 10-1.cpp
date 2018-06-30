
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int cnt=0;
    int i=1;
    for (; (double)i*(double)i<(double)N; i++)
        if (N%i==0) cnt++;
    cnt*=2;
    if (i*i==(double)N) cnt+=1;
    return cnt;
}
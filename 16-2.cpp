// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int K, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int temp=0;
    int sol=0;
    for (auto a : A){
        temp+=a;
        if (temp>=K) {
            sol++;
            temp=0;
        }
    }
    return sol;
}

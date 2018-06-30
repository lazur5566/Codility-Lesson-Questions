// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <unordered_set>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    unordered_set <int> B;
    //sort(A.begin(), A.end());
    for (int a : A){
        B.insert(a);
    }
    //for (auto b: B){
    //    if (b.second==1) return b.first;
    //}
    return B.size();
}

// or sort than cnt++ when A[i]!=A[i+1] (if ==) i++
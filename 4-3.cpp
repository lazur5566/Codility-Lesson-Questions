#include <unordered_set>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    unordered_set<int> rec;
    for (int a:A){
        rec.insert(a);
    }
    for (size_t i = 0; i < A.size(); i++){
        if (rec.count(i+1)==0) return 0;
    }
    return 1;
}

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    //for (size_t i=0; i<A.size(); i++) {cout << A[(A[i]-1)] <<endl; A[(A[i]-1)]=-A[(A[i]-1)]; }
    for (auto a: A) {
        if (abs(a)>(A.size())) return 0;
        else A[abs(a)-1] = -A[abs(a)-1];
    }
    for (auto a: A) {if (a>0) return 0;}
    return 1;
    
}
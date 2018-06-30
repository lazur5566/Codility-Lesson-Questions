#include <unordered_set>
int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int map_cnt=0;
    unordered_set<int> set_rec;
    for(size_t i = 0 ; i<A.size();  i++){
        if (A[i]<=X && set_rec.count(A[i])==0) {
            set_rec.insert(A[i]);
            map_cnt++;
        }
        if (map_cnt==X) return i;

    }
    return -1;
}

int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    vector<bool> B(X,0);
    int non_dup_cnt = 0;
    for (size_t i =0; i<A.size(); i++) {
        if (A[i]<=X && B[A[i]-1]==0) {non_dup_cnt++;B[A[i]-1]=1;}
        if(non_dup_cnt==X) return i;
    }
    return -1;
}
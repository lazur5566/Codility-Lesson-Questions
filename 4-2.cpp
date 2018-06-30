#include <unordered_set>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    unordered_set <int> rec;
    //int cur_max_n = 1;
    for (auto a : A) {
        if (rec.count(a)==0) rec.insert(a);
    }
    int i = 1; 
    while (i<A.size()){
        if (rec.count(i)==0) return i;
        i++;
    }
    return rec.count(1)? i+1 : 1;
}
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    bool has_pos = 0;
    vector<bool> B(A.size(),0);
    //int idx=0;
    for (int a : A) {
        if(a>0 && a<(int)(A.size()+1)) {B[a-1] = 1; has_pos=1; }
    }
    for (size_t j =0; j<B.size(); j++) {
        if(!B[j]) return (int)(j+1);
    }
    return has_pos? int(B.size()+1) : 1;
}
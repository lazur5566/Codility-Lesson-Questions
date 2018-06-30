vector<int> solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    // ways end at certain rung
    // at X, should come from (X-1 or X-2) +1
    int L = A.size();
    vector<long> com(L+1, 0);
    com[0] = 0; // start point
    com[1] = 1; // 1 rung
    com[2] = 2; // 1, 1 rung ; 2 rungs
    //com[3] = 3; // com[2]+1rung + com[1]+2rungs => 2 + 1
    //com[4] = 5; // com[3]+1rung + com[2]+2rungs => 3 + 2
    for (int i=3; i<=L; i++){
        com[i] = com[i-2]+com[i-1];
        com[i] = com[i]&(0xFFFFFFFF);
    }
    vector<int> ret(L,0);
    for (int i=0; i<L; i++)
        ret[i] = com[A[i]]%(1<<B[i]);
    //cout << (1<<B[0]) << endl;
    //cout << com[A[0]] << endl;
    return ret;
}
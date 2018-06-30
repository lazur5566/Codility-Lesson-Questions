vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> A((S.length()+1), 0);
    vector<int> C((S.length()+1), 0);
    vector<int> G((S.length()+1), 0);
    vector<int> T((S.length()+1), 0);
    for (size_t i =0; i<S.length(); i++){
        //cout << "S[i] = " << S[i] << endl;
        A[i+1]=(S[i]=='A')? (A[i]+1): A[i]; 
        C[i+1]=(S[i]=='C')? (C[i]+1): C[i]; 
        G[i+1]=(S[i]=='G')? (G[i]+1): G[i]; 
        T[i+1]=(S[i]=='T')? (T[i]+1): T[i]; 
    }
    vector<int> sol(P.size(), 0);
    for (size_t j =0; j<P.size(); j++){
        //cout << C[Q[j]+1] << "-" << C[P[j]] << endl;
            if ((A[Q[j]+1]-A[P[j]])>0) sol[j]=1;
            else if ((C[Q[j]+1]-C[P[j]])>0) sol[j]=2;
            else if ((G[Q[j]+1]-G[P[j]])>0) sol[j]=3;
            else if ((T[Q[j]+1]-T[P[j]])>0) sol[j]=4;
    }
    return sol;
}
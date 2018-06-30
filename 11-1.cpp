vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    vector<bool> sieve(N+1, 1); // initialize as all 1
    vector<int> rec(N+1, 0); // initialize as all 2
    sieve[0] = 0; // if prime -> 1
    sieve[1] = 0;
    int i = 2;
    while(i*i <= N) {
        if (sieve[i]==1){
            int k = i*i;
            while (k <= N){
                sieve[k]=0;
                //if (sieve[k/i]==1) rec[k]++;
                //if (k==18) cout << "i = " << i << endl;
                k+=i;
            }
        }
        i++;
    }
    i = 2;
    while(i*i <= N) {
        if (sieve[i]==1){
            int k = i*i;
            while (k <= N){
                sieve[k]=0;
                if (sieve[k/i]==1) rec[k]++;
                //if (k==18) cout << "i = " << i << endl;
                k+=i;
            }
        }
        i++;
    }
    //cout << "zz" << endl;
    vector<int> acc(N+1, 0);
    for (int i = 1; i<N+1 ;i++){
        if (rec[i]==1) acc[i]=acc[i-1]+1;
        else  acc[i]=acc[i-1];
        //cout << i << "??" << acc[i] << endl; 
    }
    //cout << "zzz" << endl;
    vector<int> ret(Q.size(), 0);
    for (size_t i = 0; i<Q.size(); i++){
        //cout << Q[i] << ";" << P[i] << endl;
        ret[i] = acc[Q[i]]-acc[P[i]-1];
    }
    //cout << "zzzz" << endl;
    return ret;
}
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    A.push_back(1);
    int L = A.size();
    /*vector<int> steps;
    int cnt = 1;
    for (int i=0; i<L; i++){
        if (A[i]==0) cnt++;
        if (A[i]==1) {
            steps.push_back(cnt);
            cnt=1;
        }
    }*/
    // create F sequence
    vector<int> F;
    F.push_back(0);
    F.push_back(1);
    //for (int i=2; F[i]<L; i++){
    int i=2;
    while(1){
        F.push_back(F[i-1]+F[i-2]);
        //cout << F[i] << L << endl;
        if(F[i]>L) break;
        i++;
    }
    // create F sequence
    //for (int j=0; j<steps.size(); j++) cout<<steps[j]<<endl;
    
    vector<int> reachable(L,-1);
    for (int f:F){
        if (A[f-1]) reachable[f-1] = 1; // if take 1 step
    }
    for (int i=0; i<L; i++){ 
        if (A[i]==0 || reachable[i]>0) continue;
        //get the optimal jump count to reach this leaf
        int min_i = -1;
        int min_value = 100000;
        for (int f:F){
            int pre_i = i - f; // predict previous i
            if (pre_i<0) break;
            if (reachable[pre_i]>0 && min_value>reachable[pre_i]){
                min_value = reachable[pre_i];
                min_i = pre_i;
            }
        }
        if (min_i!=-1) 
            reachable[i] = min_value+1;
    }
    
    return reachable[L-1];
}
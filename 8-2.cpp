// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int size = 0;
    int cur_val;
    for (int a:A){
        if (size==0){
            size++;
            cur_val = a;
        }
        else
            if(cur_val!=a)
                size--;
            else
                size++;
    }
    int candidate;
    if (size>0)
        candidate = cur_val;
    else
        return 0;
    //int idx = -1;
    int cnt = 0;
    for (int i=0; i<A.size() ; i++){
        if (A[i]==candidate)
            cnt++;
    }
    if (cnt<=A.size()/2) return 0;
    cnt = 0;
    int equi_lead_cnt=0;
    for (int i=0; i<A.size()/2 ; i++){
        if (A[i]==candidate)
            cnt++;
        if (cnt>(i+1)/2){
            equi_lead_cnt++;
            //cnt = 0;
        }
    }
    return equi_lead_cnt;
}
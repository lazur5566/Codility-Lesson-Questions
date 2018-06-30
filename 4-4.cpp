 vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> counter(N,0);
    int set_max = 0;
    int cur_max = 0;
    for (int a: A){
        if (a<=N) { 
            counter[a-1]=max(set_max, counter[a-1]);
            counter[a-1]=counter[a-1]+1; 
            //C[a-1]=0;
            cur_max = max(cur_max, counter[a-1]);
        }
        else {
            //for (int b=0; b<N; b++) B[b]=cur_max; 
            set_max=cur_max;
        }
    }
    for (int b=0; b<N; b++) counter[b]=max(set_max, counter[b]); 
    return counter;
}
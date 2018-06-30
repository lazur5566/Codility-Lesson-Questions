// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if (A.size()<3) return 0;
    vector<bool> peaks(A.size(),0);
    for(int i = 1; i<A.size()-1; ){
        if (A[i]>A[i-1] && A[i]>A[i+1]) {
            peaks[i]=1;
            i+=2;
        }
        else i++;
    }
    //cout << "peaks.size(): " << peaks.size() << endl;
    vector<int> next_peak_pos(A.size(),0);
    next_peak_pos[A.size()-1] = A.size();
    for(int i = A.size()-2; i>=0; i--){
        if (peaks[i]) next_peak_pos[i] = i;
        else next_peak_pos[i] = next_peak_pos[i+1];
    }
    int i = 1;
    vector<int> divs;
    for (; i*i<A.size(); i++){
        if (A.size()%i==0)  {
            divs.push_back(i);
            divs.push_back(A.size()/i);
        }
    }
    if (i*i==A.size()) divs.push_back(i);
    //cout <<  divs.size() << endl;
    int sol = 0;
    for (int div_length : divs){
        cout << "div_length: " << div_length << endl;
        int block_num = A.size()/div_length;
        int block_cnt = 1;
        int cur_bound= 0;
        int next_bound;
        bool vld = 0;
        for (; block_cnt<=block_num;block_cnt++ ){
            next_bound = cur_bound+div_length;
            cout <<"next_bound: " << next_bound << endl;
            vld = 0;
            for (int idx = 0; idx<div_length; idx++){
                if (next_peak_pos[idx+cur_bound] < next_bound) {
                    vld = 1;
                    break;
                }
                if (idx==(div_length-1) && !vld)  break;
            }
            cur_bound = next_bound;
            if (!vld) break;
        }
        cout << "block_num: " << block_num << endl;
        if (block_cnt==(block_num+1) && vld) sol=max(sol, block_num);
    }
    return sol;
}
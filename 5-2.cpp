int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int zero_cnt=0;
    int acc_cnt=0;
    for (int a :A){
        if (a==0){
            zero_cnt+=1;
        }
        else {
            acc_cnt+=zero_cnt;
            if (acc_cnt>1000000000) return -1;
        }
    }
    return acc_cnt;
}
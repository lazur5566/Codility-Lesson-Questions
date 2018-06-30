#include <stack>
int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    stack<int> down_fishes;
    int survived_cnt=0;
    int i=0 ;
    while(i< B.size()){
        if(B[i]==0){
            //while(A[i]>down_fishes.top()&&!down_fishes.empty())
            //    down_fishes.pop();
                
            while(!down_fishes.empty())
                if (A[i]>down_fishes.top()) down_fishes.pop();
                else break;
            if (down_fishes.empty()) 
                survived_cnt++;
        }
        else 
            down_fishes.push(A[i]);
        i++;
    }
    return survived_cnt+down_fishes.size();
}
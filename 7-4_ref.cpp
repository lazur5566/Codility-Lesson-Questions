#include <stack>
int solution(vector<int> &A, vector<int> &B) {
    if(A.size() < 2) return A.size();

    int nalive = 0;//upstream存活的鱼
    int i = 0;
    stack<int> safe;//downstream暂时存活的鱼
    while(i < B.size()){
        if(B[i] == 0){
            while(!safe.empty() && A[i] > safe.top()){//栈不为空的条件很重要
                safe.pop();
            }
        }else{
            safe.push(A[i]);//压入downstream的鱼
        }
        if(safe.empty()){//pop操作也可能导致栈空，因此这一步放在后面
            while(B[i] == 0 && i < B.size()){//数组不越界的条件很重要
                nalive++;
                i++;
            }
            if(i == B.size())
                return nalive;
            safe.push(A[i]);//压入downstream的鱼
        }
        i++;//处理下一条鱼
    }
    return nalive + safe.size();
}
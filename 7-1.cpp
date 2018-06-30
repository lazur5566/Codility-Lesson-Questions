// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <stack>
int solution(vector<int> &H) {
    // write your code in C++14 (g++ 6.2.0)
    stack<int> lazur;
    int cnt = 0;
    for (int h : H){
        while(!lazur.empty() && h<lazur.top()){
            lazur.pop();
        }
        if (lazur.empty() || h>lazur.top()){
            lazur.push(h);
            cnt++;
        }
    }
    return cnt;
}
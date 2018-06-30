// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <stack>
int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    stack<char> tmp;
    for (char s : S){
        if (s=='{'||s=='['||s=='(') tmp.push(s);
        else if (s=='}' && tmp.top()=='{') tmp.pop(); 
        else if (s==']' && tmp.top()=='[') tmp.pop(); 
        else if (s==')' && tmp.top()=='(') tmp.pop(); 
        else return 0;
    }
    
    return tmp.empty();
}
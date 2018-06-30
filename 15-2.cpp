// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <unordered_set>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    /*int cnt = 0;
    for (int i = 0; i< A.size(); i++){
        int j = i+1;
        while (j<A.size() && ){
            if() cnt++;
        }
    }*/
    unordered_set<int> s;
    for (int a: A)
        s.insert(abs(a));
    
    return s.size();
}

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int L = A.size();
    int i = 0;
    int j = L-1;
    int ans = L;
    while (i<j){
        while (A[i]==A[i+1] && i!=j){
            ans--;
            i++;
        }
        while (A[j]==A[j-1] && i!=j){
            ans--;
            j--;
        }
        if (A[i]+A[j]==0) {
            ans--;
            j--;
            i++;
        }
        else if (A[i]+A[j]<0) {
            i++;
        }
        else {
            j--;
        }
    }
    return ans;
}


// above wrong in some cases??

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int L = A.size();
    int i = 0;
    int j = L-1;
    int ans = L;
    int sum;
    while (i<j){
        while (A[i]==A[i+1] && i!=j){
            ans--;
            i++;
        }
        while (A[j]==A[j-1] && i!=j){
            ans--;
            j--;
        }
        if (i == j)
            break; // ZZZZZZZZZZZZZZZZZZZZ
        sum = A[i]+A[j]; 
        
        if (sum==0) {
            ans--;
            j--;
            i++;
        }
        else if (sum<0) {
            i++;
        }
        else {
            j--;
        }
    }
    return ans;
}
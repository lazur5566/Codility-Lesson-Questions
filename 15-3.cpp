//As every time we extend the range, 
//all the possible length of the slices before extension will have one more move and one new slice, 
//the length of which is the same as the extended range, can be added.
// you can use includes, for example:
// #include <algorithm>

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int solution(int M, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size(); 
    vector<int> found(M+1,-1); 
    int r = 0; 
    int l = -1;
    int cnt = 0;
    for (   ; r < N; r++){  
        
        if (found[A[r]] > l) // in e.g. when r=3, cond true 
            l = found[A[r]]; // l=2
        // e.g. if valid interval is 0~2, then possible pair is 
        // (0,0);(0,1)(1,1);(0,2)(1,2)(2,2)
        // which is 0--1 + 1--1 + 2--1
        cnt += (r-l); // 3-2 = 1 which is (3,3)
        
        found[A[r]] = r;
        if (cnt > 1000000000)
            return 1000000000;
        
    }

    return cnt;
}
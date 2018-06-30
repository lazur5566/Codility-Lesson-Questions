// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

/////////////// better one /////////////////

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> opt(A.size(),0); // best sol that end at index i

    for (int i=1; i<A.size(); ++i){
        int j = 6;
        if(i-j>=0) opt[i] = opt[i-j]+A[i];
        else opt[i] = A[i];
        for(j = 5; j>0; --j){
            if(i-j>=0) 
                opt[i] = max(opt[i], opt[i-j]+A[i]);
            else 
                opt[i] = A[i];
        }
    }
    return  A[0]+opt[A.size()-1];
}
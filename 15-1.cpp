// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int L = A.size();
    int sol = 0;
    sort(A.begin(),A.end());
    for (int x = 0; x<L; x++){
        int z = x+2;
        for (int y = x+1; y<L; y++){
            while (z<L && A[x]+A[y] > A[z])
                z++;
            //if ((A[x]+A[y] > A[x]) && (A[x]+A[y] > A[x]) && (A[x]+A[y] > A[x])) sol++;
            sol+=z-y-1; // because cur z is 1 larger than the acceptable minimum largest z
        }
    }
    return sol;
}
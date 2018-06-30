int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    int M = C.size();
    int beg = 1;
    int end = M; // M=5, N=4
  
    int answer = -1;
    while (beg <= end){
        int mid = (beg + end) / 2; // 2
        
        vector<int> prefix_sum(2*M+1, 0);
        for (int i=0; i < mid; i++) // i=0~1
            prefix_sum[C[i]]++; 
            // prefix_sum[C[0]]: prefix_sum[4]++
            // prefix_sum[C[1]]: prefix_sum[6]++
        // prefix_sum: [0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0]
      
        for (int i=1; i <= 2 * M; i++)
            prefix_sum[i] += prefix_sum[i - 1];
        // prefix_sum: [0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 2]
        
        int failed=0;
        for (int i=0; i < N; i++)
            if (prefix_sum[B[i]] == prefix_sum[A[i] - 1]) 
            // means between idx B[i] and idx A[i], there's no new nail
                failed = 1;

        if (failed){
            beg = mid + 1;
        }
        else {
            end = mid - 1;
            answer = mid;
        }
    }
  
    return answer;
}


//// N^2 solution

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    int M = C.size();
    vector<bool> nailed(N,0);
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++){
            if (C[i]>=A[j] && C[i]<=B[j]) nailed[j]=1;
        }
        int cnt = 0;
        for (bool n:nailed){
            if(n) cnt++;
            else break;
        }
        if (cnt==L) return (i+1);
    }
    return -1;
}

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
#include <numeric>

//bool zz(size_t i1, size_t i2, vector<int> &C) {return C[i1] < C[i2];}
int getMinIndex(int startPlank, int endPlank, vector<int> &C, vector<size_t> &idx,int preIndex) {
    int min = 0;
    int max = C.size() - 1;
    int minIndex = -1;
    while (min <= max) {
        int mid = (min + max) / 2;
        if (C[mid] < startPlank)
            min = mid + 1;
        else if (C[mid] > endPlank)
            max = mid - 1;
        else {
            max = mid - 1;
            minIndex = mid;
        }
    }
    if (minIndex == -1)
        return -1;
    int minIndexOrigin = idx[minIndex];
    //find the smallest original position of nail that can nail the plank
    for (int i = minIndex; i < C.size(); i++) {
        if (C[i] > endPlank)
            break;
        if (minIndexOrigin>idx[i]) minIndexOrigin = idx[i];
        // we need the maximal index of nails to nail every plank, so the
        // smaller index can be omitted
        if (minIndexOrigin <= preIndex)
            return preIndex;
    }
    return minIndexOrigin;
}

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    int M = C.size();

    // sorting C
    vector<size_t> idx(C.size());
    iota(idx.begin(), idx.end(), 0); // create a [0,1,...,C.size()-1] array

    // sort indexes based on comparing values in C
    sort(idx.begin(), idx.end(), [&C](size_t i1, size_t i2) {return C[i1] < C[i2];});
    sort(C.begin(), C.end());
    //for(auto i:idx) cout<<i<<endl;
    
    int result = 0;
    for (int i = 0; i < N; i++) {
    //find the earlist position that can nail each plank, and the max value for all planks is the result
        result = getMinIndex(A[i], B[i], C, idx, result);
        if (result == -1) return -1;
    }
    return result + 1;
}
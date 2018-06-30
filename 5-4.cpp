// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    double avg_2=0;
    double avg_3=0;
    double g_min=((double)A[A.size()-1]+(double)A[A.size()-2])/(double)2;
    int min_pos=A.size()-2;
    
    for (int i = A.size()-1; i>=2; i--){
        avg_3=((double)A[i]+(double)A[i-1]+(double)A[i-2])/(double)3;
        avg_2=((double)A[i]+(double)A[i-1])/(double)2;
        if (g_min>=avg_3){
            g_min = avg_3;
            min_pos = i-2;
        }
        if (g_min>=avg_2){
            g_min = avg_2;
            min_pos = i-1;
        }
    }
    avg_2=((double)A[1]+(double)A[0])/(double)2;
    
    if (g_min>=avg_2){
        g_min = avg_2;
        min_pos = 0;
    }
    return min_pos;
}
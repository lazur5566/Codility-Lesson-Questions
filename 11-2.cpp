vector<int> solution(vector<int> &A) {
    //the number that may appear will be [1 ... 2 * N].
    int N = A.size();
    int size = (N * 2 + 1);    
    vector<int> occurrence(size, 0);
    
    //the space to hold the answer for each value from 1 ... 2 * N.
    //for now we initialize it 
    vector<int> answer(size, 0);
    
    //allocate the memory for the result.
    vector<int> result(N, N);
        
    //now we check the array A and count the occurance for each number.
    int i;
    for (i = 0; i < N; i++){
        occurrence[A[i]]++;
    }
        
    //now we compute the answer.
    for (i = 1; i <= N * 2; i++){
        int num = occurrence[i];
        
        //the number doesn't in the array A, we can neglect it.
        if (num == 0){
            continue;
        }

        //if it appears in the array A, 
        //subtract its counts from cells at itss multiples in the answer array.
        int j;
        for (j = i; j <= N * 2; j += i){
            answer[j] -= num;
        }        
    }
    
    //as the answer array contains the offset to N, 
    //N + answer[A[i]] will give the answer for each.
    for (i = 0; i < N; i++){
        result[i] += answer[A[i]];
    }
    
    return result;
}
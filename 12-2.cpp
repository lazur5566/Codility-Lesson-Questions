// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int gcd(int a, int b){
    if (a%b==0) return b;
    else return gcd(b, a%b);
}
// If two numbers have the same prime divisors then
// the gcd of both numbers and the result of each number divided by
// gcd must have the same prime divisors to
bool HasSamePrimeDivisor(int a, int b){
    int gcdValue = gcd(a,b);
    int gcdA;
    int gcdB;
    while(a!=1) {
        gcdA = gcd(a,gcdValue);
        if(gcdA==1)
            break;
        a = a/gcdA;
    }
    if(a!=1)  {
        return false;
    }
    while(b!=1) {
        gcdB = gcd(b,gcdValue);
        if(gcdB==1)
            break;
        b = b/gcdB;
    }
    return b==1;        
}
int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    int cnt = 0;
    for(int i=0; i<A.size(); i++){
        int a = A[i];
        int b = B[i];
        if (HasSamePrimeDivisor(a, b)) cnt++;
    }
    return cnt;
}



// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int gcd(int a, int b){
    if (a%b==0) return b;
    else return gcd(b, a%b);
}
// If two numbers have the same prime divisors then
// the gcd of both numbers and the result of each number divided by
// gcd must have the same prime divisors to
bool HasSamePrimeDivisor(int a, int b){
    int gcdValue = gcd(a,b);
    int gcdA;
    int gcdB;
    int newa = a/gcdValue;
    int newb = b/gcdValue;
    while(newa!=1) {
        gcdA = gcd(newa,gcdValue);
        if(gcdA==1)
            break;
        newa = newa/gcdA;
    }
    if(newa!=1)  {
        return false;
    }
    while(newb!=1) {
        gcdB = gcd(newb,gcdValue);
        if(gcdB==1)
            break;
        newb = newb/gcdB;
    }
    return newb==1;        
}
int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    int cnt = 0;
    for(int i=0; i<A.size(); i++){
        int a = A[i];
        int b = B[i];
        if (HasSamePrimeDivisor(a, b)) cnt++;
    }
    return cnt;
}
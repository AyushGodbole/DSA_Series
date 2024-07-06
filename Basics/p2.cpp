// Factorial , Sum of N natural

#include <bits/stdc++.h>
using namespace std;

int fact(int n){
    // base case
    if(n==0 || n==1) return 1;

    int res = n*fact(n-1);

    return res;
}

int Nsum(int n){
    if(n==0) return 0;
    int res = n + Nsum(n-1);
    return res;
}

int main(){

    cout<<fact(6);
    return 0;
}
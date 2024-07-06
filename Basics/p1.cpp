// sum , avg , min , max

#include <bits/stdc++.h>
using namespace std;

int min(vector<int> arr){
    int minVal = INT_MAX;
    for(auto ele : arr){
        minVal = min(minVal,ele);
    }

    return minVal;
}

int max(vector<int> arr){
    int maxVal = INT_MIN;
    for(auto ele : arr){
        maxVal = max(maxVal,ele);
    }

    return maxVal;
}

void func(vector<int> arr){
    int sum = 0;
    int n = arr.size();
    for(auto ele : arr){
        sum+=ele;
    }

    cout<<"Sum"<<sum<<endl;
    cout<<"AVG"<<(sum/n)<<endl;
}

int main(){
    return 0;
}
// Sorting techniques

#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[],int n){
    for(int i=0; i<=n-2; i++){
        int min_idx = i;
        for(int j=i; j<=n-1; j++){
            if(arr[j]<arr[min_idx]){
                min_idx = j;
            }
        }

        swap(arr[i],arr[min_idx]);
    }
}

void bubble_sort(int arr[], int n){
    for(int i=n-1; i>=1; i--){
        bool didSwapped = false;
        for(int j=0; j<=i-1; j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j+1],arr[j]);
                didSwapped = true;
            }
        }
        if(didSwapped==false) break;
    }
}

void insertion_sort(int arr[], int n){
    for(int i=0; i<=n-1; i++){
        int j = i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}

int main(){

    
    return 0;
}
#include <iostream>
using namespace std;

void sortArr(int arr[],int n){
    for (int i=0, j=n-1; i<n, j>i; i++,j--){
        if (arr[i]>arr[j]){
            swap (arr[i],arr[j]);
        }
    }
}

void printarr(int arr[],int n){
    for (int i=0;i<n;i++){
        cout <<arr[i]<<" ";
    }cout << endl;
}


int main(){
    int arr[10]={0,1,0,1,1,1,0,1,0,1};
    
    printarr(arr,10);
    sortArr(arr,10);
    printarr(arr,10);
}
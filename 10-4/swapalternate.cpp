#include <iostream>
using namespace std;

void printarr(int arr[],int n){
    for (int i=0;i<n;i++){
        cout <<arr[i]<<" ";
    }cout << endl;
}

void swapAlternate(int arr[],int n){
    for (int i =0;i<n;i+=2)
    {
        if (i<n){
            swap(arr[i],arr[i+1]);
        }
    }
}

int main (){
    int arr[10]={0,2,4,6,8,10,12,14,16,18};
    printarr(arr,10);
    swapAlternate(arr,10);
    printarr(arr,10);
}
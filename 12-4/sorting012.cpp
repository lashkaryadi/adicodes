#include <iostream>
using namespace std;

void sortArr(int arr[],int n){
    for (int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if (arr[i]>arr[j]){
           swap(arr[i],arr[j]);
        }
        }
    }
}
void printArr(int arr[],int n){
    for (int i=0;i<n;i++){
        cout << arr[i]<<" ";
    }cout << endl;
}
int main (){
    int arr[10]={1,2,0,2,1,0,2,1,0,0};
    printArr(arr,10);
    sortArr(arr,10);
    printArr(arr,10);
}
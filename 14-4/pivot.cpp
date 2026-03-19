#include <iostream>
using namespace std;

int pivotArr(int arr[],int n){
    int s=0,e=n-1,mid;
    mid=s+(e-s)/2;
    while (s<e){
        
        if (arr[mid]>=arr[0]){
            s=mid+1;
        }
        else {
            e=mid;
        }
        mid=s+(e-s)/2;
        
    }
    return arr[s];
}

int main(){
    int arr[5]={7,9,0,1,2};
    cout << pivotArr(arr,5);
}
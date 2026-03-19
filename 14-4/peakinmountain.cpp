#include <iostream>
using namespace std;

int peakArr(int arr[],int n){
    //binary search
    int s=0,e=n-1,mid;
    
    while(s<e){
        mid=s + ((e-s)/2);
        if (arr[mid]<arr[mid+1]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s +((e-s)/2);

    }
    return arr[mid];
}

int main (){
    int arr[10]={0,1,2,3,4,5,6,9,2,1};
    cout<<peakArr(arr,10);
}
#include<iostream>
using namespace std;

int binarySearch(int arr[],int n, int s,int e,int key){
    int  mid = s + (e-s)/2;
    while (s<=e){
        if (key <arr[mid]){
            e=mid -1;

        }
        else if (arr[mid]==key){
            return mid;
        }
        else {
            s=mid+1;
        }
        mid = s + (e-s)/2;
    }
    return mid;
}
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
    return s;
}


int main(){
    int key;
    cin>>key;
    int arr[5]={7,9,0,1,2};
    int pivot=pivotArr(arr,5);
    if (key>=arr[pivot] && arr[4]>=key ){
        cout <<  binarySearch(arr,5,pivot,4,key);
    }
    else {
        cout <<  binarySearch(arr,5,0,pivot,key);
    }

}




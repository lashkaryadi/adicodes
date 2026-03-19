#include <iostream>
using namespace std;

int firstOcc(int arr[],int n,int key){
    //binary search
    int s=0,e=n-1;
    int mid=s+((e-s)/2), ans=-1;
    while (s<=e){
        if (arr[mid]==key){
            ans=mid;
            e=mid-1;

        }

        else if (arr[mid]<key){
            s=mid+1;

        }
        else {
            e=mid-1;
        }
        mid= s +((e-s)/2);

    }
    return ans;
}

int lastOcc(int arr[],int n,int key){

    int s=0,e=n-1,mid=s+((e-s)/2),ans=-1;
    while (s<=e){
        if (arr[mid]==key){
            ans=mid;
            s=mid+1;
        }
        else if (arr[mid]<key){
            s=mid+1;

        }
        else {
            e=mid-1;
        }
        mid = s + ((e-s)/2);

    }
    return ans;
}


int main (){
    int key;
    cin>> key;

    int arr[10]={1,2,2,2,3,3,3,3,4,4};
    
    
   cout << (lastOcc(arr,10,key)-firstOcc(arr,10,key))+1;

}
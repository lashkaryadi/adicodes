#include <iostream>
using namespace std;

int firstOcc(int arr[],int n, int key){
    int s=0, e=n-1;
    int mid=s+ (e-s)/2, ans=-1;

    while(s<=e){
        if (arr[mid]==key){
            ans=mid;
            e=mid-1;
        }

        else if(arr[mid]<key){
           s=mid+1;

        }
        else {
            e=mid-1;
        }
        mid=s+ (e-s)/2;
    }
    return ans;
   
}

int lastOcc(int arr[],int n,int key){
    int s=0,e=n-1;
    int mid=s +(e-s)/2;
    int ans=-1;
    while (s<=e){
        if (arr[mid]==key){
            ans=mid;
            s=mid+1;

        }
        else if (arr[mid]<key){
            s=mid+1;

        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
  return ans;

}
void printArr(int arr[],int n){
    for (int i=0;i<n;i++){
        cout << arr[i]<<" ";
    }
}

int main(){
    int arr[10]={0,2,2,2,3,4,5,7,7,8};
   
    cout<<"First Occurence of 2 is at Index" <<firstOcc(arr,10,2);
    cout<<"\nFirst Occurence of 2 is at Index" <<lastOcc(arr,10,2);
}
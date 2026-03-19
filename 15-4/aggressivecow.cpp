//largest minimum diastance between agressie cows

#include <iostream>
using namespace std;
#include <array>

bool possibleDis(int arr[],int size, int cow,int mid){
    int disCount=arr[0]; 
    int cowCount=1;
    for (int i=0;i<size;i++){
        if (arr[i]-disCount>=mid){
            cowCount++;
            if (cowCount==cow){
                return true;
            }
            disCount=arr[i];
        }
    }
    return false;
}

int aggCows(int arr[],int size,int cow){
    int start=0;
    
    int end=arr[size-1]-arr[0];
    int mid =start +(end-start)/2;
    //binary search 
    int ans=-1;
    while (start<=end){
        if (possibleDis(arr,size,cow,mid)){
            start=mid+1;
            ans=mid;
        }
        else {  
            end=mid-1;
        }
        mid =start +(end-start)/2;
    }

    return ans;
}

int main(){
    int arr[7]={0,1,2,3,4,5,6};
    cout << aggCows(arr,7,2);
}
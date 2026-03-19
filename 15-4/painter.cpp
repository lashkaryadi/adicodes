//maximum area one painter will paint

#include <iostream>
using namespace std;
bool possibleSol(int arr[],int size,int painter,int mid){
    int areaSum=0;
    int painterCount=1;
    for (int i=0;i<size;i++){
        if (arr[i]+areaSum<=mid){
            areaSum+= arr[i];
        }
        else{
            painterCount++;
            if (painterCount>painter || arr[i]>mid){
                return false;
            }   
            areaSum=arr[i];
        }
    }
    return true;
}
int painter(int arr[],int size,int painter){
    int start=0;
    int sum=0;
    for (int i=0;i<size;i++)    
    {
        sum+=arr[i];
    }
    int end=sum;
    //binary search
    int mid=start + (end-start)/2;
    while(start<=end){
        if (possibleSol(arr,size,painter,mid))
        {
            end=mid-1;
        }
        else {
            start=mid+1;
        }
        mid=start + (end-start)/2;
    }
    return mid;
}


int main (){
    int arr[4]={1,2,3,4};
    cout << painter(arr,4,2);
    
}
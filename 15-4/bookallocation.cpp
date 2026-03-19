//maximum number of pages to be read by one student

#include <iostream>
using namespace std;
bool possibleSol(int arr[],int size,int student,int mid){
    int pageSum=0,studentCount=1;
    for (int i=0;i<size;i++){
        if (pageSum+arr[i]<=mid){
            pageSum+=arr[i];
            
        }
        else{
            studentCount++;
            if(studentCount>student || arr[i]>mid){
                return false;
            }
            pageSum=arr[i];
        }
        
    }
    return true;
}
int bookAlloc(int arr[],int size,int student){
    //binary search 
    int start=0,sum=0;
    for (int i=0;i<size;i++){
        sum+=arr[i];
    }
    int end=sum;
    int mid=start + (end-start)/2;
    while(start<=end){
        if (possibleSol(arr,size,student,mid)){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid=start + (end-start)/2;
    }
    return mid;
}

int main(){
    int arr[4]={20,20,20,20};
    int student=2;

cout<< bookAlloc(arr,4,2);

}
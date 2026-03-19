#include <iostream>
using namespace std;

void printarr(int arr[],int n){
    for (int i=0;i<n;i++){
        cout <<arr[i]<<" ";
    }cout << endl;
}

int uniqueNumber(int arr[],int size){
    int ans=0;
     for(int i=0;i<size;i++){
        ans=ans^arr[i];           
        }
        cout << ans;
        return ans;
     }


int main(){
   int arr[10]={2,3,4,2,3,4,1};
   printarr(arr,10);
   uniqueNumber(arr,10);

}
#include <iostream>
using namespace std;
void revarr(int arr[],int n){
    for (int i=0;i<n/2; i++){
        swap(arr[i],arr[n-1-i]);
    }
}
void printarr(int arr[],int n){
    for (int i=0;i<n;i++){
        cout <<arr[i]<<" ";
    }
}
int main(){
int arr[10]={1,2,3,4,5,6,7,8,9};
printarr(arr,10);
cout<<endl;
revarr(arr,10);
printarr(arr,10);

}
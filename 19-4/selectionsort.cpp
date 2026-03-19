//selection sort
//useful when array size is small
#include <iostream>
using namespace std;

void selectionSort(int arr[],int size){
    for (int i=0;i<size-1;i++){
        for (int j=i+1;j<size;j++){
            if (arr[j]<arr[i]){
                swap(arr[j],arr[i]);
            }
        }
    }
}
void printArr(int arr[],int size){
    for (int i=0;i<size;i++){
        cout << arr[i]<<" ";
    }
}


int main(){
     int arr[6]={2,3,1,2,1,2};
    selectionSort(arr,6);
    printArr(arr,6);


}
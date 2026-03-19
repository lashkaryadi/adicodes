//bubble sort 


#include <iostream>
using namespace std;

void bubbleSort(int arr[],int size){
    int i=1;
    while (i<size){
        int temp = arr[i];
        for (int j=i-1;j>=0;j--){
            if (temp < arr[j]){
                arr[j+1]= arr[j];
            }
            else {
                break;
            }
            arr[j]=temp;
        }
        i++;
    }
}
void printArr(int arr[],int size){
    for (int i=0;i<size;i++){
        cout << arr[i]<<" ";
    }
    cout << endl;
}

int main(){
    int arr[9]={5,4,6,1,7,1,8,3,9};
    printArr(arr,9);
    bubbleSort(arr,9);
    printArr(arr,9);
}

#include <iostream>
using namespace std;

void arrSearch(int arr[],int n,int key){
    for (int i=0;i<n;i++){
        if (arr[i]==key){
            cout<< i;

    }
}
}
void  keyOccurence(int arr[], int n, int key){

int i=0,j=n-1;
while (i<j){
    if (arr[i]==key){
        break;
    }
    i++;
}
while (j>i){
    if (arr[j]==key){
       break;
    }
    j++;
}
cout << i<< " "<<j;
}
void printArr(int arr[],int n){
    for (int i=0;i < n;i++){
        cout << arr[i] << " ";
    }cout << endl;
}

int main (){
    int arr[7]={0,0,1,1,2,2,2};
    printArr(arr,7);
   // arrSearch(arr,7,2);
    keyOccurence(arr,7,2);

}
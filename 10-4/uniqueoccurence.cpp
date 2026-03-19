#include <iostream>
using namespace std;

void printarr(int arr[],int n){
    for (int i=0;i<n;i++){
        cout <<arr[i]<<" ";
    }
}

void Occurence(int arr[],int size,int key){
    int count=0;
    for (int i=0;i<size;i++){
        if (arr[i]==key)
        count++;
    }
    cout<<key<<" "<<count;
}
int main(){

}
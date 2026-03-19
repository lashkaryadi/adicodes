#include <iostream>
using namespace std;

void pairSum(int arr[],int n,int key){

    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if ((key - arr[i] -arr[j])==0){
                cout << arr[i]<<" "<< arr[j] << endl;
            }
        }
    }
}



int main(){
   int key; 
   cin >> key;
int arr[10]={1,2,3,4,5,6,7,8,9,0};

pairSum(arr,10,key);


}
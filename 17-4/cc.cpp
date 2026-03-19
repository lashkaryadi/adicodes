#include <iostream>
using namespace std;

int minArr(int arr[],int size){
   sort(arr[0],arr[size -1]);
   return arr[0];
}
int arrInp(int arr[],int size){
    for (int i=0;i<size;i++){
        cin >> arr[i];
    }
    return 0;
}

int main() {
	// your code goes here
int t;
cin >> t;
while (t>0){
    int n;
    int arr[n];
    arrInp(arr,n);
    if (arr[0]==arr[n-1] && arr[0]==minArr(arr,n)){
        cout << "YES";
        
    }
    else {
        cout << "NO";
    }
    t--;
}
}

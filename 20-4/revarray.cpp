//revarray using vector
#include <iostream>
#include <vector>
using namespace std;

vector<int> revArray(vector<int> arr)
{
int s=0,e=arr.size()-1;
while (s<=e){
    swap (arr[s],arr[e]);
    s++;
    e--;
}
return arr;
}

void printArr(vector<int> arr){
    int i=0;
    while (i<arr.size()){
        cout<<arr[i]<<" ";
        i++;
    }
    cout << endl;
}
int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(2);

    printArr(revArray(arr));

}
#include <iostream>
#include <vector>
using namespace std;

vector<int> selectionSort(vector<int>& nums) {
        int mini, size=nums.size();
        for (int i=0;i<size;i++){
            mini = i;
            for(int j=i+1;j<size;j++){
                if(nums[j]<nums[mini])
                mini=j;
            }
            swap(nums[mini],nums[i]);
        }
        return nums;
    }

    void print(vector<int> n){
        for (int i=0;i<n.size();i++){
            cout << n[i]<< '\t';
        }
    }
    

vector<int> bubbleSort(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(nums[j]>nums[j+1])
                swap(nums[j],nums[j+1]);
            }
        }
        cout << n;
        return nums;
    }    
  
    vector<int> insertionSort(vector<int>& nums) {
        int n=nums.size();
        for (int i=0;i<n;i++){
            for (int j=i;j>=0;j--){
                if(nums[j]<nums[j-1]){
                    swap(nums[j],nums[j-1]);
                }
            }
        }
        return nums;
    }    

int main(){
    vector <int> nums={1,2,5,43,0,32};
    print (nums);
    insertionSort(nums);
    cout << endl;
    print (nums);
    


}
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int maxFreq(vector<int>& nums){
    int res,maxi=0;
    map <int,int> freq;
    
    for (auto high : nums){
        freq[high]++;
    }

    for ( auto& it : freq){
        if(maxi < it.second){
        maxi = it.second;
        res = it.first;}
    }
    return res;

}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n); 
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }

    cout << maxFreq(nums);

}
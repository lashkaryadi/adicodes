//leetcode problem 1330

#include <iostream>
#include <vector>   
using namespace std;
    int score(vector<int> v){
       int i=1,score=0;
       while (i<v.size()){
        score = score + abs(v[i-1]-v[i]);
        i++;
       }
       return score;
    }
    vector<int> rev(vector<int> v,int l,int r){
        while (l<=r){
            swap(v[l],v[r]);
            l++;
            r--;
        }
        return v;
    }
 
    int main(){
        vector<int> nums;
        int maxi=-1,ans=0;
        nums.push_back(1);
        nums.push_back(1);
        nums.push_back(1);
        nums.push_back(2);
        nums.push_back(2);
        nums.push_back(2);
        nums.push_back(2);
        cout<< score(nums);
        int l=0,r=nums.size()-1;
        while (l<=r){
           int sum;
           sum=score(rev(nums,l,r));
           ans=max(maxi,sum);
           
           l++;
           r--;
        }
        cout<< ans;
    }




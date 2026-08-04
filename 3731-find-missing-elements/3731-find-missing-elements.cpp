class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++){
            if(nums[i] < mini){
                mini = nums[i];
            }
            if(nums[i] > maxi){
                maxi = nums[i];
            }
        }

        vector <int> temp;
        for (int i = mini ; i <= maxi ; i++){
            temp.push_back(i);
        }

        for( int i = 0; i<nums.size();i++){
            erase(temp,nums[i]);
        }
        
        return temp;
    }
};
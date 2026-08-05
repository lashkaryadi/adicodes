class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=0,white=0,blue=0;
        for(auto it : nums){
            if(it == 0)red++;
            else if(it == 1)white++;
            else blue++;
        }
        nums.clear();
        nums.insert(nums.end(),red,0);
        nums.insert(nums.end(),white,1);
        nums.insert(nums.end(),blue,2);
    }
};
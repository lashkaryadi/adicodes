class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total_xor = 0;
        int zero_count = 0;
        int n = nums.size();

        // Calculate total XOR and count zeros
        for (int x : nums) {
            total_xor ^= x;
            if (x == 0) {
                zero_count++;
            }
        }

        // Case 1: If total XOR is non-zero, the whole array is the answer
        if (total_xor != 0) {
            return n;
        }

        // Case 2: Total XOR is zero
        // If all elements are zero, no non-zero XOR subsequence exists
        if (zero_count == n) {
            return 0;
        }

        // Otherwise, we can remove exactly one element to make XOR non-zero
        // The length becomes n - 1
        return n - 1;
    }
};   
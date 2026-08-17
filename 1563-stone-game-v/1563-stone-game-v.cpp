class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        // dp[i][j] = maximum score Alice can get
        // from the subarray i...j
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // mx helps us quickly get:
        // best score + sum of the side we keep
        vector<vector<int>> mx(n, vector<int>(n, 0));

        // Base case: only one stone
        for (int i = 0; i < n; i++) {
            mx[i][i] = stoneValue[i];
        }

        // j = right end of the current interval
        for (int j = 1; j < n; j++) {

            // mid = position where the left and right
            // sums are closest to each other
            int mid = j;

            int sum = stoneValue[j];
            int right = 0;

            // Try all left boundaries
            for (int i = j - 1; i >= 0; i--) {

                sum += stoneValue[i];

                // Move mid while the right side is
                // still smaller than or equal to the left side
                while (mid > i &&
                       (right + stoneValue[mid]) * 2 <= sum) {
                    right += stoneValue[mid];
                    mid--;
                }

                // The two sides have equal sums.
                // Alice can choose whichever side is better.
                if (right * 2 == sum) {
                    dp[i][j] = mx[i][mid];
                }

                // Left side is smaller.
                // The left side survives.
                if (mid != i) {
                    dp[i][j] = max(
                        dp[i][j],
                        mx[i][mid - 1]
                    );
                }

                // Right side is smaller.
                // The right side survives.
                if (mid != j) {
                    dp[i][j] = max(
                        dp[i][j],
                        mx[j][mid + 1]
                    );
                }

                // Save the best value for future intervals.
                mx[i][j] = max(
                    mx[i][j - 1],
                    dp[i][j] + sum
                );

                mx[j][i] = max(
                    mx[j][i + 1],
                    dp[i][j] + sum
                );
            }
        }

        return dp[0][n - 1];
    }
};
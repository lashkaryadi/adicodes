class Solution {
public:   
  int rowWithMax1s(vector<vector<int>> &mat) {
    int index = -1, max_sum = 0;

    for (int i = 0; i < mat.size(); i++) {
        int low = 0, high = mat[i].size() - 1;
        int position = mat[i].size();

        while (low <= high) {
            int mid = (low + high) / 2;

            if (mat[i][mid] == 1) {
                position = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        int ones = mat[i].size() - position;

        if (ones > max_sum) {
            max_sum = ones;
            index = i;
        }
    }

    return index;
  }
};
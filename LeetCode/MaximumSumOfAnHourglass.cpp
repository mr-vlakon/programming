class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int max = 0;
        for (decltype(grid.size()) i = 0; i != grid.size() - 2; ++i) {
            for (decltype(grid[i].size()) j = 0; (j + 3) <= grid[i].size(); ++j) {
                int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
                sum += grid[i + 1][j + 1];
                sum += grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
                if (sum > max) {
                    max = sum;
                }                   
            }    
        }
        return max;
        
    }
};

int main() {
  
  
  return 0;  
}

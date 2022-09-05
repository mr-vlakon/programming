class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
            vector<vector<int>> result(grid.size());
            for (decltype(grid.size()) i = 0; i != grid.size(); ++i) {
                for (decltype(grid.size()) j = 0; j != grid.size(); ++j) {
                    result[j % grid.size()].push_back(grid[i][j]);
                }
            }
            int cnt = 0;
            for (decltype(grid.size()) i = 0; i != grid.size(); ++i) {
                for (decltype(result.size()) j = 0; j != result.size(); ++j) {
                    if (grid[i] == result[j])
                        ++cnt;
                }
            }                        
            return cnt;
    }
};

int main() {
  
  
  return 0;  
}

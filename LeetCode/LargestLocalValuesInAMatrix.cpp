class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> res;
        for (decltype(grid.size()) i = 0; i != grid.size() - 2; ++i) {
            vector<int> tmp;
            for (decltype(grid[i].size()) j = 0; j <= grid[j].size() - 3; ++j) {
                tmp.push_back(max({grid[i][j], grid[i][j + 1], grid[i][j + 2],
                                  grid[i + 1][j], grid[i + 1][j + 1], grid[i + 1][j + 2],
                                 grid[i + 2][j], grid[i + 2][j + 1], grid[i + 2][j + 2]}));
            }
            res.push_back(tmp);
        }
        return res;
    }
};

int main() {
  
  
  return 0;  
}

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int answer = 0;
        vector<int> maxRow(grid.size(), 0);
        int maxVal = 0;
        vector<int> maxCol(grid[0].size(), 0);     
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                maxVal = max(maxVal, grid[i][j]);
                maxCol[j] = max(maxCol[j], grid[i][j]);
            }
            maxRow[i] = maxVal;
            maxVal = 0;
        }
        int tmp = 0;
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                tmp = grid[i][j];
                grid[i][j] = max(min(maxRow[i], maxCol[j]), grid[i][j]);
                if ((grid[i][j] - tmp) > 0) {
                    answer += grid[i][j] - tmp;
                    maxRow[i] = max(maxRow[i], grid[i][j]);     
                    maxCol[j] = max(maxCol[j], grid[i][j]);
                }   
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}

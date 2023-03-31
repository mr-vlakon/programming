class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> visitedRow(grid.size(), 0);
        vector<int> visitedCol(grid[0].size(), 0);
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    visitedRow[i] += 1;
                    visitedCol[j] += 1;
                }
            }            
        }
        int cnt = 0;
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                if (grid[i][j] == 1 && (visitedRow[i] > 1 || visitedCol[j] > 1)) {
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};

int main() {
  
  
  
  return 0;  
}

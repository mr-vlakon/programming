class Solution {
public:
    void generate(const vector<vector<int>> &grid, int i, int j, int k) {
        if (grid[i][j] == 2) {
            if (k == p)
                ++cnt;
            return;
        }
        
        if ((i + 1) < grid.size() && grid[i + 1][j] != -1 && visited[i + 1][j] == false) {
            visited[i + 1][j] = true;    
            generate(grid, i + 1, j, k + 1);
            visited[i + 1][j] = false;
        }

        if ((i - 1) >= 0 && grid[i - 1][j] != -1 && visited[i - 1][j] == false) {
            visited[i - 1][j] = true;
            generate(grid, i - 1, j, k + 1);
            visited[i - 1][j] = false;
        }
        
        if ((j + 1) < grid[0].size() && grid[i][j + 1] != -1 && visited[i][j + 1] == false) {
            visited[i][j + 1] = true;
            generate(grid, i, j + 1, k + 1);
            visited[i][j + 1] = false;
        }
        if ((j - 1) >= 0 && grid[i][j - 1] != -1 && visited[i][j - 1] == false) {
            visited[i][j - 1] = true;
            generate(grid, i, j - 1, k + 1);
            visited[i][j - 1] = false;
        }
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int startRow = 0;
        int startCol = 0;
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                if (grid[i][j] == 1 && status) {
                    status = false;
                    startRow = i;
                    startCol = j;
                } else if (grid[i][j] == 0) {
                    ++p;
                }
            }
        }
        visited.resize(grid.size(), vector<bool>(grid[0].size(), false));
        visited[startRow][startCol] = true;
        generate(grid, startRow, startCol, 0);
        return cnt;
    }
private:
    bool status = true;
    int p = 1;
    vector<vector<bool>> visited;
    int cnt = 0;
};

int main() {
  
  
  return 0;  
}

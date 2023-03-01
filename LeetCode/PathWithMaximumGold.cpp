class Solution {
public:
    void generate(const vector<vector<int>> &grid, int i, int j, int k, int &sum) {
        answer = max(answer, sum);
        if (k == (grid.size() * grid[0].size())) {
            return;
        } 
        if ((i + 1) < grid.size() && (grid[i + 1][j] != 0) && visited[i + 1][j] == false) {
            visited[i + 1][j] = true;  
            sum += grid[i + 1][j];  
            generate(grid, i + 1, j, k + 1, sum);
            sum -= grid[i + 1][j];
            visited[i + 1][j] = false;
        }

        if ((i - 1) >= 0 && grid[i - 1][j] != 0 && visited[i - 1][j] == false) {
            visited[i - 1][j] = true;
            sum += grid[i - 1][j];
            generate(grid, i - 1, j, k + 1, sum);
            sum -= grid[i - 1][j];
            visited[i - 1][j] = false;
        }
        
        if ((j + 1) < grid[0].size() && grid[i][j + 1] != 0 && visited[i][j + 1] == false) {
            visited[i][j + 1] = true;
            sum += grid[i][j + 1];
            generate(grid, i, j + 1, k + 1, sum);
            sum -= grid[i][j + 1];
            visited[i][j + 1] = false;
        }
        if ((j - 1) >= 0 && grid[i][j - 1] != 0 && visited[i][j - 1] == false) {
            visited[i][j - 1] = true;
            sum += grid[i][j - 1];
            generate(grid, i, j - 1, k + 1, sum);
            sum -= grid[i][j - 1];
            visited[i][j - 1] = false;
        }
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        visited.resize(grid.size(), vector<bool>(grid[0].size(), false));        
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                if (grid[i][j] != 0 && visited[i][j] == false) {
                    visited[i][j] = true;
                    s = grid[i][j];
                    generate(grid, i, j, 0, s);
                    visited[i][j] = false;
                }
            }
        }
        return answer;
    }
private:
    int s = 0;
    int answer = 0;
    vector<vector<bool>> visited;
};

int main() {
  
  
  return 0;  
}

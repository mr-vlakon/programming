class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        queue<pair<int, int>> q;
        int cnt = 0;
        for (int i = 0; i != grid2.size(); ++i) {
            for (int j = 0; j != grid2[0].size(); ++j) {
                if (grid2[i][j] == 1) {
                    q.push({i, j});
                    bool status = false;
                    while (!q.empty()) {
                        auto top = q.front();
                        q.pop();
                        if (grid1[top.first][top.second] == 0) {
                            status = true;
                        } 
                        if ((top.first + 1) < grid2.size() &&
                         grid2[top.first + 1][top.second] == 1) {
                             grid2[top.first + 1][top.second] = -1;
                            q.push({top.first + 1, top.second});
                        }
                        if ((top.second + 1) < grid2[0].size() && 
                        grid2[top.first][top.second + 1] == 1) {
                            grid2[top.first][top.second + 1] = -1;
                            q.push({top.first, top.second + 1});
                        }
                        if ((top.second - 1) >= 0 && 
                        grid2[top.first][top.second - 1] == 1) {
                            grid2[top.first][top.second - 1] = -1;
                            q.push({top.first, top.second - 1});
                        }
                        if ((top.first - 1) >= 0 && 
                        grid2[top.first - 1][top.second] == 1) {
                            grid2[top.first - 1][top.second] = -1;
                            q.push({top.first - 1, top.second });
                        }
                        grid2[top.first][top.second] = -1;
                        
                    }
                    if (!status)
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

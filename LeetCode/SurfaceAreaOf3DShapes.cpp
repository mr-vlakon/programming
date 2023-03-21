class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int answer = 0;
        int maxH = 0;
        for (int i = 0; i != grid.size(); ++i) {
            maxH = max(*max_element(grid[i].cbegin(), grid[i].cend()), maxH);
        }
        int h = 1;
        int cnt = 0;
        while (h <= maxH) {
            for (int i = 0; i != grid.size(); ++i) {
                for (int j = 0; j != grid[0].size(); ++j) {
                    cnt = 6;
                    if (grid[i][j] >= h) {
                        if (h > 1) {
                            --cnt;
                        }
                        if (h < grid[i][j]) {
                            --cnt;
                        }
                        if ((j - 1) >= 0 && grid[i][j - 1] >= h) {
                            --cnt;
                        }
                        if ((j + 1) < grid[0].size() && grid[i][j + 1] >= h) {
                            --cnt;
                        }
                        if ((i - 1) >= 0 && grid[i - 1][j] >= h) {
                            --cnt;
                        }
                        if ((i + 1) < grid.size() && grid[i + 1][j] >= h) {
                            --cnt;
                        }
                        answer += cnt;
                    }
                }
            }
            ++h;
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}

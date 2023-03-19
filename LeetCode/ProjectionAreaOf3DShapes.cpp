class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int answer = 0;
        vector<int> maxV(grid[0].size());
        int maxR = 0;
        int tmp = 0;
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                if (grid[i][j] != 0) {
                    ++tmp;
                }
                maxV[j] = max(grid[i][j], maxV[j]);
                maxR = max(grid[i][j], maxR);
            }
            answer += maxR;
            maxR = 0;
        }
        for (const auto &e: maxV) {
            answer += e;
        }
        answer += tmp;
        return answer;
    }
};

int main() {
  
  
  return 0;  
}

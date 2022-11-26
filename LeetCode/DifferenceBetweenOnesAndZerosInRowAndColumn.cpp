class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int> onesInRow;
        vector<int> zeroInRow;
        for (const auto &e: grid) {
            int ones = count(e.cbegin(), e.cend(), 1);
            onesInRow.push_back(ones);
            zeroInRow.push_back(e.size() - ones);
        }
        
        vector<vector<int>> transponse(grid[0].size());
        int row = 0;
        for (int i = 0; i != grid[0].size(); ++i) {
            for (int j = 0; j != grid.size(); ++j) {
                transponse[i].push_back(grid[j][i]);
            }
        }
        
        vector<int> onesInCol;
        vector<int> zeroInCol;
        for (const auto &e: transponse) {
            int ones = count(e.cbegin(), e.cend(), 1);
            onesInCol.push_back(ones);
            zeroInCol.push_back(e.size() - ones);
        }
        
        vector<vector<int>> answer(grid.size());
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                answer[i].push_back(onesInRow[i] + onesInCol[j] - zeroInRow[i] - zeroInCol[j]);
            }
            
        }
 
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}

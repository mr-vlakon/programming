class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        vector<vector<int>> mat(grid.size(), vector<int>(grid[0].size()));
        int startR = grid.size() - 1;
        int startC = 0;
        unordered_map<int, int> um;
        unordered_map<int, int> diag;
        int tmpR = 0;
        int tmpC = 0;
        while (startR != 0 || startC != grid[0].size()) {
            tmpR = startR;
            tmpC = startC;
            while (tmpR < grid.size() && tmpC < grid[0].size()) {
                ++um[grid[tmpR][tmpC]];
                ++tmpR;
                ++tmpC;
            }
            tmpR = startR;
            tmpC = startC;
            while (tmpR < grid.size() && tmpC < grid[0].size()) {
                --um[grid[tmpR][tmpC]];       
                if (um[grid[tmpR][tmpC]] == 0) {
                    um.erase(grid[tmpR][tmpC]);
                }
                mat[tmpR][tmpC] = abs(static_cast<int>(um.size()) - static_cast<int>(diag.size()));
                ++diag[grid[tmpR][tmpC]];
                ++tmpR;
                ++tmpC;
            }
            if (startR > 0) --startR;
            else ++startC;
            diag.clear();
            um.clear();
        }
        return mat;
    }
};

int main() {
  
  
  
  
  return 0;  
}

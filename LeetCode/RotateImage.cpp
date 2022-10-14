class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> result(matrix.size());
        for (decltype(matrix.size()) i = 0; i != matrix.size(); ++i) {
            int k = 0;
            for (decltype(matrix[i].size()) j = 0; j != matrix[i].size(); ++j) {
                result[k].push_back(matrix[i][j]);
                ++k;
            }
        }
        
        for (auto &e: result)
            reverse(e.begin(), e.end());
        
        matrix = result;
        
    }
};

int main() {
  
  
  return 0;  
}

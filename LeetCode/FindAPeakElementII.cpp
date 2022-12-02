class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        for (int i = 0; i != mat.size(); ++i) {
            for (int j = 0; j != mat[i].size(); ++j) {
                if (mat[i][j] > (j - 1 < 0 ? - 1 : mat[i][j - 1]) && mat[i][j] > 
                                 (i - 1 < 0 ? - 1 : mat[i - 1][j]) && mat[i][j] > 
                    (i + 1 > mat.size() - 1 ? - 1 : mat[i + 1][j]) && mat[i][j] 
                    > (j + 1 > mat[i].size() - 1 ? - 1 :mat[i][j + 1])) {
                    return {i, j};
                }
            }
        }
        return {0, 0};
    }  
};

int main() {
  
  
  
  return 0;  
}

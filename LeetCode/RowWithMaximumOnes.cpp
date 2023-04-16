class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> v(mat.size(), 0);
        for (int i = 0; i != mat.size(); ++i) {
            for (int j = 0; j != mat[0].size(); ++j) {
                if (mat[i][j] == 1) {
                    v[i]++;
                }
            }
        }
        int maxV = 0;
        for (const auto &e: v) {
            maxV = max(maxV, e);
        }
        int answer = 0;
        for (int i = 0; i != v.size(); ++i) {
            if (v[i] == maxV) {
                return {i, maxV};
            }
        }
        return {0,0};        
    }
};

int main() {
  
  
  
  return 0;  
}

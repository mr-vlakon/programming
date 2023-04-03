class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> mat(rowSum.size(), vector<int>(colSum.size(), 0));
        int tmp = 0;
        for (int i = 0; i != rowSum.size(); ++i) {
            for (int j = 0; j != colSum.size(); ++j) {
                mat[i][j] = min(rowSum[i], colSum[j]);
                tmp = min(rowSum[i], colSum[j]);
                rowSum[i] -= tmp;
                colSum[j] -= tmp;
            }
        }
        return mat;
    }
};

int main() {
  
  
  
  return 0;  
}

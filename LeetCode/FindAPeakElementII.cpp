class Solution {
public:
    void recursive(const vector<vector<int>> &num, int &start, int &end, int &mid) {
        if (start > end) {
            return;
        }
        maxInd = -1;
        maxV = 0;
        for (int k = 0; k != num.size(); ++k) {
            if (num[k][mid] > maxV) {
                maxV = num[k][mid];
                maxInd = k;
            }
        }
        tmp1 = ((mid - 1) < 0) ? -1 : num[maxInd][mid - 1];
        tmp2 = ((mid + 1) >= num[0].size()) ? -1 : num[maxInd][mid + 1];
        if (tmp1 < num[maxInd][mid] && tmp2 < num[maxInd][mid]) {
            answer = {maxInd, mid};
            return;
        }
        if (tmp1 > num[maxInd][mid]) {
            end = mid - 1;
            mid = (start + end) / 2;
            recursive(num, start, end, mid);
        } else if (tmp2 > num[maxInd][mid]) {
            start = mid + 1;
            mid = (start + end) / 2;
            recursive(num, start, end,  mid);
        }
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        if (mat.size() == 1) {
            return {0, 0};
        }
        answer = {-1, -1};
        int start = 0;
        int end = mat[0].size() - 1;
        int mid = (start + end) / 2;
        recursive(mat, start, end, mid);
        return answer;
    }
private:
    int tmp1 = 0;
    int tmp2 = 0;
    int maxV = 0;
    int maxInd = -1;
    vector<int> answer;
};
/*
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
*/
int main() {
  
  
  
  return 0;  
}

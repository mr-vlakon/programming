class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        vector<int> hashCol(mat.size() * mat[0].size(), 0);
        vector<int> hashRow(mat.size() * mat[0].size(), 0);
        for (int i = 0; i != mat.size(); ++i) {
            for (int j = 0; j != mat[0].size(); ++j) {
                hashCol[mat[i][j] - 1] = j;
                hashRow[mat[i][j] - 1] = i;
            }
        }
        vector<int> cntCol(mat[0].size(), 0);
        vector<int> cntRow(mat.size(), 0);
        for (int i = 0; i != arr.size(); ++i) {
            cntCol[hashCol[arr[i] - 1]]++;
            cntRow[hashRow[arr[i] - 1]]++;
            if ((cntCol[hashCol[arr[i] - 1]] == mat.size()) || (cntRow[hashRow[arr[i] - 1]] == mat[0].size())) {         
                return i;
            }
        }
        return 0;
    }
};

int main() {
  
  
  
  return 0;  
}

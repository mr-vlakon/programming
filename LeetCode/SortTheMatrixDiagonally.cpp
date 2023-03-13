class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int startRow = mat.size() - 1;
        int startCol = 0;
        int tmpCol = startCol;
        int tmpRow = startRow;
        int i = 0;
        vector<int> tmp;
        while (startCol != (mat[0].size() - 1) || startRow != 0) {
            tmpCol = startCol;
            tmpRow = startRow;
            tmp.resize(0);
            while (tmpCol < mat[0].size() && tmpRow < mat.size()) {
                tmp.push_back(mat[tmpRow][tmpCol]);
                tmpCol++;
                tmpRow++;
            }
            tmpCol = startCol;
            tmpRow = startRow;
            sort(tmp.begin(), tmp.end());
            i = 0;
            while (tmpCol < mat[0].size() && tmpRow < mat.size()) {
                mat[tmpRow][tmpCol] = tmp[i];
                tmp.push_back(mat[tmpRow][tmpCol]);
                tmpCol++;
                tmpRow++;
                ++i;
            }
            if (startRow != 0) {
                --startRow;
            } else if (startRow == 0) {
                startCol++;
            }
        }
        return mat;
    }
};

int main() {

  
  
  return 0;  
}

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> result;
        int startRow = 0;
        int startCol = 0;
        int direction = 0;
        while (startRow != mat.size() && startCol != mat[0].size()) {
            result.push_back(mat[startRow][startCol]);
            if (direction == 0 && startRow == 0 && startCol != (mat[0].size() - 1)) {
                direction = 1;
                ++startCol;
            } else if (direction == 1 && startCol == 0 && (startRow != (mat.size() - 1))) {
                direction = 0;
                startRow++;
            } else if (direction == 1 && startRow == (mat.size() - 1)) {
                direction = 0;
                startCol++;
            } else if (direction == 0 && startCol == (mat[0].size() - 1)) {
                direction = 1;
                ++startRow;
            } else if (direction == 0) {
                --startRow;
                ++startCol;
            } else if (direction == 1) {
                ++startRow;
                --startCol;
            }
        }
        return result;
    }
};

int main() {
  
  
  
  return 0;  
}

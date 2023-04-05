class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rowCol(max(static_cast<int>(matrix.size()),static_cast<int>(matrix[0].size())), 0);
        for (int i = 0; i != matrix.size(); ++i) {
            for (int j = 0; j != matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    if (rowCol[i] == -1) {
                        rowCol[i] = 2;
                    } else if (rowCol[i] == 0){
                        rowCol[i] = 1;
                    }                    
                    if (rowCol[j] == 1) {
                        rowCol[j] = 2;
                    } else if (rowCol[j] == 0){
                        rowCol[j] = -1;
                    }
                }
            }
        }
        for (int i = 0; i != matrix.size(); ++i) {
            if (rowCol[i] == 2 || rowCol[i] == 1) {
                for (int j = 0; j != matrix[0].size(); ++j) {
                    matrix[i][j] = 0;    
                }
            }
        }

        for (int j = 0; j != matrix[0].size(); ++j) {
            if (rowCol[j] == 2 || rowCol[j] == -1) {
                for (int i = 0; i != matrix.size(); ++i) {
                    matrix[i][j] = 0;    
                }
            }
        }
    }
};

int main() {
  
  
  
  return 0;  
}

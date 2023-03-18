class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<vector<int>> trans(mat[0].size(), vector<int>(mat.size(), 0));
        int start = mat.size() - 1;
        for (int i = 0; i != mat.size(); ++i) {
            for (int j = 0; j != mat[0].size(); ++j) {
                trans[j][start] = mat[i][j];
            }
            --start;
        }
        if (trans == target) {
            return true;
        }
        cout << "In" << endl;
        mat = trans;
        start = mat.size() - 1;
        for (int i = 0; i != mat.size(); ++i) {
            for (int j = 0; j != mat[0].size(); ++j) {
                trans[j][start] = mat[i][j];
            }
            --start;
        }
        if (trans == target) {
            return true;
        }
        mat = trans;
        start = mat.size() - 1;
        for (int i = 0; i != mat.size(); ++i) {
            for (int j = 0; j != mat[0].size(); ++j) {
                trans[j][start] = mat[i][j];
            }
            --start;
        }
        if (trans == target) {
            return true;
        }
        mat = trans;
        start = mat.size() - 1;
        for (int i = 0; i != mat.size(); ++i) {
            for (int j = 0; j != mat[0].size(); ++j) {
                trans[j][start] = mat[i][j];
            }
            --start;
        }
        return trans == target;    
    }
};

int main() {
  
  
  return 0;  
}

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> mat(2, vector<int>(colsum.size(), 0));
        for (int j = 0; j != mat[0].size(); ++j) {
            if (colsum[j] == 2) {
                mat[0][j] = 1;
                mat[1][j] = 1;
                colsum[j] = 0;
                upper--;
                lower--;
            }
        }
        for (int j = 0; j != mat[0].size(); ++j) {
            if (colsum[j] == 1) {
                if (upper > 0) {
                    --upper;
                    mat[0][j] = 1;
                    colsum[j] = 0;
                } else if (lower > 0) {
                    --lower;
                    mat[1][j] = 1;
                    colsum[j] = 0;
                } else {
                    return {};
                }
            }
        }
        if (upper != 0) {
            return {};
        }
        if (lower != 0) {
            return {};
        }
        return mat;
    }
};

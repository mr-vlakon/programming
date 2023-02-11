class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<vector<int>> transponse(matrix[0].size(), vector<int>(matrix.size(), 0));
        vector<int> vMin;
        for (int i = 0; i != matrix.size(); ++i) {
            vMin.push_back(*min_element(matrix[i].cbegin(), matrix[i].cend()));
            for (int j = 0; j != matrix[0].size(); ++j) {
                transponse[j][i] = matrix[i][j];
            }
        }
        vector<int> vMax;
        for (const auto &e: transponse) {
            vMax.push_back(*max_element(e.cbegin(), e.cend()));
        }
        vector<int> answer;
        for (int i = 0; i != matrix.size(); ++i) {
            for (int j = 0; j != matrix[0].size(); ++j) {
                if (matrix[i][j] == vMin[i] && matrix[i][j] == vMax[j]) {
                    answer.push_back(matrix[i][j]);
                }
            }
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}

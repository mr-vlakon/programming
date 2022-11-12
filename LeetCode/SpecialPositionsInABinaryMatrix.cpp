class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int answer = 0;
        for (decltype(mat.size()) i = 0; i != mat.size(); ++i) {
            for (decltype(mat[0].size()) j = 0; j != mat[0].size(); ++j) {
                if (mat[i][j] == 1) {
                    auto cnt1 = count(mat[i].cbegin(), mat[i].cend(), 1);
                    if (cnt1 != 1) break;
                    int cnt1InCol = 0;
                    for (int k = 0; k != mat.size(); ++k) {
                        if (mat[k][j] == 1) {
                            ++cnt1InCol;
                        }
                        if (cnt1InCol > 1)
                            break;
                    }
                    if (cnt1InCol == 1)
                        ++answer;
                }
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}

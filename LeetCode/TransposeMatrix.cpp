class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        auto it = matrix.cbegin();
        auto size = it->size();
        vector<vector<int>> result(size);
        int q = 0;
        for (decltype(result.size()) i = 0; i != size; ++i) {
            int k = 0;
            for (decltype(size) j = 0; j != matrix.size(); ++j) {
                result[q].push_back(matrix[k][q]);
                k++;
            }
            ++q;
        }
        return result;
    }
};

int main() {
  
  
  return 0;  
}

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (decltype(matrix.size()) i = 0; i != matrix.size() - 1; ++i) {
            if (vector<int>{matrix[i].cbegin(), matrix[i].cend() - 1} 
                != vector<int>{matrix[i + 1].cbegin() + 1, matrix[i + 1].cend()})
                return false;
        }
        return true;  
    }
};

int main() {
  
  
  return 0;  
}

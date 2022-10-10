class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        size_t i = 0;
        int sum = 0;
        while (i != mat.size()) {
            if (i != mat.size() - i - 1)
                sum += mat[i][mat.size() - i - 1] + mat[i][i];
            else
                sum += mat[i][i];
            ++i;
        }
        return sum;
    }
};

int main() {
  
  
  
  return 0;  
}

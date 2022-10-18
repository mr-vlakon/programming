class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int left_limit = 0;
        int right_limit = matrix[0].size();
        int i = left_limit;
        int up_limit = 0;
        int down_limit = matrix.size();
        int k = up_limit;
        
        if (right_limit == 1) {
            for (const auto &e: matrix) {
                result.push_back(e[0]);
            }
            return result;
        }
        
        
        while (!(left_limit >= right_limit || up_limit >= down_limit)) {
            i = left_limit;
            k = up_limit;
            while (i < right_limit) {
                result.push_back(matrix[k][i]);
                ++i;
            }
            if (( i >= right_limit - 1) &&  k >= down_limit - 1)
                break;
            k++;
            while (k < down_limit) {
                result.push_back(matrix[k][right_limit - 1]);
                ++k;
            }
            if (i == left_limit + 1)
                break;
            if (k == down_limit + 1)
                break;

            i = right_limit - 2;
            
            
            while (i >= left_limit) {
                result.push_back(matrix[down_limit - 1][i]);
                --i;
            }
            
            
            k = down_limit - 2;
            if (i == left_limit + 1)
                break;
            if (k == down_limit + 1)
                break;
            if (( i >= right_limit - 1) ||  k >= down_limit - 1)
                break;
            while (k > up_limit) {
                result.push_back(matrix[k][left_limit]);
                --k;
            }
            while (k < up_limit) {
                result.push_back(matrix[k][i]);
                ++k;
            }
            right_limit--;
            down_limit--;
            left_limit++;
            ++up_limit;
        }
        return result;
        
    }
};

int main() {
  
  
  return 0;  
}

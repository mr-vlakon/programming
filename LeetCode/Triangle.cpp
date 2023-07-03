class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = 1; i != triangle.size(); ++i) {
            triangle[i][0] += triangle[i - 1][0];
            triangle[i][triangle[i].size() - 1] += triangle[i - 1][triangle[i].size() - 2];    
            for (int j = 1; j != triangle[i].size() - 1; ++j) {
                triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
            }
        }    
        return *min_element(triangle.back().cbegin(), triangle.back().cend());    
    }
};

int main() {


  
  return 0;
}

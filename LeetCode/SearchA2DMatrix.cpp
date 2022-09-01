class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(const auto &e: matrix) {
            if(find(e.begin(), e.end(), target) != e.end())
                return true;
        }
        return false;
    }
};

int main() {
  
  return 0;  
}

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> v(51, -1);
        for (int i = 0; i != ranges.size(); ++i) {
            for (int k = ranges[i][0]; k <= ranges[i][1]; ++k) {
                v[k] = 1;
            }
        }
        while (left <= right) {
            if (v[left] == -1) {
                return false;
            }
            ++left;
        }
        return true;
    }
};

int main() {
  
  
  return 0;  
}

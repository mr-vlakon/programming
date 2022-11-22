class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        for (int j = 0; j <= arr.size() - m; ++j) {
            vector<int> v(arr.cbegin() + j, arr.cbegin() + j + m);
            int cnt = 1;
            for (int i = j + m; i <= arr.size() - m; i += m) {
                if (vector<int>(arr.cbegin() + i, arr.cbegin() + i + m) == v) {
                    ++cnt;
                } else {
                    break;
                }
                if (cnt >= k) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
  
  
  return 0;  
}

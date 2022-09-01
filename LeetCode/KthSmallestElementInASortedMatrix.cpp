class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> v;
        for (const auto &e: matrix) {
            for (const auto &p: e) {
                v.push_back(p);
            }
        }
        sort(v.begin(), v.end());
        return *(v.begin() + k - 1);
    }
};

int main() {
  
  return 0;  
}

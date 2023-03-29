class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int, int>> v;
        for (const auto &e: arr) {
            v.push_back({abs(e - x), e});
        }
        sort(v.begin(), v.end(), [](pair<int, int> &lhs, pair<int, int> &rhs) {
            return lhs.second < rhs.second;
        });
        stable_sort(v.begin(), v.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
            return lhs.first < rhs.first;
        });
        vector<int> result;
        for (int i = 0; i != k; ++i) {
            result.push_back(v[i].second);
        }
        sort(result.begin(), result.end());
        return result;       
    }
};

int main() {
  
  
  return 0;  
}

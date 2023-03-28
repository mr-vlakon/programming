class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double, pair<int, int>> > v;
        for (int i = 0; i != arr.size(); ++i) {
            for (int j = i + 1; j != arr.size(); ++j) {
                    v.push_back({static_cast<double>(arr[i]) / static_cast<double>(arr[j]), {arr[i], arr[j]}});
            }
        }
        sort(v.begin(), v.end(), [] (pair<double, pair<int, int>> &lhs, pair<double, pair<int, int>> &rhs) {
            return lhs.first < rhs.first;
        });        
        return {v[k - 1].second.first, v[k - 1].second.second};
    }
};

int main() {
  
  
  
  return 0;  
}

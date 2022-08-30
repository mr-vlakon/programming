class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, size_t> map;
        for (const auto &e: nums)
            ++map[e];
        vector<pair<int,size_t>> v;
        for (const auto &e: map) {
            v.push_back({e.first, e.second});
        }
        sort(v.begin(), v.end(), 
             [](const pair<int,size_t> &lhs, const pair<int,size_t> &rhs) {
            return lhs.second > rhs.second;
        });
        vector<int> result;
        size_t i = 0;
        while (i != k) {
            result.push_back(v[i].first);
            ++i;
        }
        return result;
    }
};

int main() {
  
  return 0;  
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, size_t> um;
        for (const auto &e: words) {
            ++um[e];
        }
        vector<pair<string,size_t>> v;
        for (const auto &e: um) {
            v.push_back({e.first, e.second});
        }
        sort(v.begin(), v.end());
        stable_sort(v.begin(), v.end(), 
             [](const pair<string,size_t> &lhs, const pair<string,size_t> &rhs) {
                 return lhs.second > rhs.second;
             });
        vector<string> result;
        for (decltype(result.size()) i = 0; i != k; ++i) {
            result.push_back(v[i].first);
        }
        return result;
    }
}

int main() {
  
  return 0;  
}

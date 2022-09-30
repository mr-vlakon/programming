class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, size_t> um;
        for (const auto &e: nums) {
            if (e % 2 == 0)
                ++um[e];
        }
        vector<pair<int, size_t>> v;
        for (const auto &e: um) {
            v.push_back({e.first, e.second});
        }
        sort(v.begin(), v.end(), 
             [=](const pair<int, size_t> &lhs, const pair<int, size_t> &rhs) {
                return lhs.first < rhs.first; 
             });
        stable_sort(v.begin(), v.end(), 
             [=](const pair<int, size_t> &lhs, const pair<int, size_t> &rhs) {
                return lhs.second > rhs.second; 
             });
        if (v.size() != 0)
            return v[0].first;
        else
            return -1;
        
    }
};

int main() {
  
  
  
  return 0;  
}

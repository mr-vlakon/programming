class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, size_t> mp;
        for (const auto &e: arr) {
            ++mp[e];
        }
        
        vector<int> result;
        for (const auto &e : mp) {
            result.push_back(e.second);
        }
        sort(result.begin(), result.end()); 
        auto p = unique(result.begin(), result.end());
        if (p == result.end())
            return true;
        return false;
    }
};

int main() {
  
  return 0;  
}

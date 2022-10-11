class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, size_t> um;
        for (const auto &e: word) {
            ++um[e];
        }
        
        vector<size_t> v;
        for (const auto &e: um) {
            v.push_back(e.second);
        }
        sort(v.begin(), v.end());
        
        for (auto &e: v) {
            --e;                
            if (count(v.cbegin(), v.cend(), v.back()) + count(v.cbegin(), v.cend(), 0) == v.size()) {
                return true;
            }
            ++e;
        }
            
        return false;
    }
};

int main() {
  
  
  
  return 0;  
}

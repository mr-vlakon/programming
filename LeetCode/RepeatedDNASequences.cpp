class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return {};
        unordered_map<string, size_t> um;
        for (decltype(s.size()) i = 0; i <= s.size() - 10; ++i) {
            ++um[{s.cbegin() + i, s.cbegin() + i + 10}];
        }
        vector<string> res;
        for (const auto &e: um) {
            if (e.second > 1)
                res.push_back(e.first);
        }
        return res;
    }
};

int main() {
  
  
  
  return 0;  
}

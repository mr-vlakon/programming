class Solution {
public:
    bool is_unique(const string &s) {
        unordered_map<char, size_t> mp;
        if (s.size() <= 1) return true;
        for (const auto &e: s) {
            ++mp[e];
        }
        for (const auto &e: mp) {
            if (e.second > 1)
                return false;
        }
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        if (s.size() == 1)
            return 1;
        if (s.size() >= 1) {
            istringstream iss(s);
            string s2;
            iss >> s2;
            if (s2.size() == 0) {
                return 1;
            }
        }
        istringstream is(s);
        string s1;
        is >> s1;
        if (s1.size() < s.size()) {
            s = s1 + " ";
        } else
            s = s1;
        
        for(decltype(s.size()) i = 0; i <= s.size(); ++i) {
            for(decltype(s.size()) j = i; j <= s.size(); ++j) {
                if (is_unique({s.begin() + i, s.begin() + j})) {
                    if(max <= j - i)
                        max = j - i;
                } else {
                    break;
                }
            }   
        }
        return max;
    }
};

int main() {
  
  return 0;  
}

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream is(s);
        string s1;
        unordered_map<char, string> um;
        unordered_map<string, char> rum;
        int i = 0;
        while(is >> s1) {
            auto it = um.find(pattern[i]);
            auto iter = rum.find(s1);
            if (it != um.cend() && it->second != s1) return false;
            if (iter != rum.cend() && iter->second != pattern[i]) return false;
            um[pattern[i]] = s1;
            rum[s1] = pattern[i];
            ++i;
        }
        if (i != pattern.size()) return false;
        return true; 
    }
};

int main() {
  
  

  return 0;
}

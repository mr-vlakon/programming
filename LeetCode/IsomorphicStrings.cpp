class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> um;
        unordered_map<char, int> rum;
        for (int i = 0; i != s.size(); ++i) {
            auto it = um.find(s[i]);
            if (it != um.cend()) {
                if (it->second != t[i])
                    return false;
            }
            auto iter = rum.find(t[i]);
            if (iter != rum.cend()) {
                if (iter->second != s[i])
                    return false;
            }  
            um[s[i]] = t[i];
            rum[t[i]] = s[i];
        }
        return true;
    }
};

int main() {
  
  
  
  
  return 0;  
}

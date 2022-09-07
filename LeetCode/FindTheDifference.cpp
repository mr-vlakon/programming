class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (decltype(t.size()) i = 0; i != s.size(); ++i) {
            if (s[i] != t[i])
                return t[i];
        }
        return t[t.size() - 1];
    }
};

int main() {
  
  
  return 0;  
}

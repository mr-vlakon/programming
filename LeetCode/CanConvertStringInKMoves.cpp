class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.size() != t.size()) return false;
        vector<int> diff(26, 0);
        for (int i = 0; i != s.size(); ++i) {
            if ((t[i] - s[i]) >= 0) {
                diff[t[i] - s[i]]++;
            } else {
                diff[26 - (s[i] - 'a') + (t[i] - 'a')]++;
            }
        }
        for (int i = 1; i != diff.size(); ++i) {
            if((i + 26*(diff[i] - 1)) > k) {
                return false;
            }
        }
        return true;       
    }
};

int main() {
  
  
  
  
  return 0;  
}

class Solution {
public:
    bool isPalindrome(string s) {
        string s1;
        for (auto &c : s) {
            if (isspace(c) || ispunct(c)) {        
            } else {
                c = tolower(c);
                s1.push_back(c);
            }
        }
        string s2 = s1;
        reverse(s1.begin(), s1.end());
        if (s1 == s2) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
  
  return 0;
}

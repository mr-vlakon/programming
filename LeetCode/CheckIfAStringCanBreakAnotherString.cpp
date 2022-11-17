class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i != s1.size(); ++i) {
            if (s1[i] >= s2[i])
                ++cnt1;
            if (s1[i] <= s2[i])
                ++cnt2;
        }
        if (cnt1 == s1.size() || cnt2 == s1.size()) return true;
        return false;
    }
};

int main() {
  
  
  
  return 0;  
}

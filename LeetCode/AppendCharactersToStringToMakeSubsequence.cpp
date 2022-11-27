class Solution {
public:
    int appendCharacters(string s, string t) {
        int tmp = 0;
        int prev = 0;
        bool status = true;
        for (int i = 0; i != t.size(); ++i) {
            status = false;
            for (int j = prev; j != s.size(); ++j) {
                if (t[i] == s[j]) {
                    ++tmp;
                    status = true;
                    prev = j + 1;
                    break;
                }
            }
            if (!status)
                break;
        }
        return t.size() - tmp;
    }
};

int main() {
  
  
  
  return 0;  
}

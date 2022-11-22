class Solution {
public:
    string capitalizeTitle(string title) {
        istringstream is(title);
        string result;
        string s;
        while (is >> s) {
            if (s.size() <= 2) {
                for (auto &e: s) {
                    e = tolower(e);
                }
            } else {
                s[0] = toupper(s[0]);
                for (int i = 1; i != s.size(); ++i) {
                    s[i] = tolower(s[i]);
                }
            }
            result += s + " ";
        }
        result.erase(--result.cend());
        return result;
    }
};

int main() {
  
  
  
  return 0;  
}

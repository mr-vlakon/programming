class Solution {
public:
    void generate(const string &s, int i, string &str) {
        if (i == s.size()) {
            result.push_back(str);
            return;
        }
        if (!isdigit(s[i])) {
            string tmp = str;
            str.push_back(tolower(s[i]));
            generate(s, i + 1, str);
            tmp.push_back(toupper(s[i]));
            generate(s, i + 1, tmp);
        } else {
            str.push_back(s[i]);
            generate(s, i + 1, str);
        }

    }
    vector<string> letterCasePermutation(string s) {
        string empty;
        generate(s, 0, empty);
        return result;
    }
private:
    vector<string> result;
};

int main() {
  
  
  return 0;  
}

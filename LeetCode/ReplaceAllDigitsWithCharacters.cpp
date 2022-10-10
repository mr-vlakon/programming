class Solution {
public:
    string replaceDigits(string s) {
        string res;
        int i = 0;
        for (const auto &e: s) {
            if (i % 2 == 0)
                res.push_back(e);
            else {
                char c = s[i] - '0' + (s[i - 1]);
                res.push_back(c);
            }
            ++i;
        }
        return res;
    }
};

int main() {
  
  
  return 0;  
}

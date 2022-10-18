class Solution {
public:
    string reverseWords(string s) {
        istringstream is(s);
        string str;
        string res;
        while (is >> str) {
            reverse(str.begin(), str.end());
            res += str + " ";
        }
        res.erase(--res.cend());
        return res;
    }
};

int main() {
  
  
  
  return 0;  
}

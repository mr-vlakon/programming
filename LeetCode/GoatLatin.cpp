class Solution {
public:
    bool isVowel(const char &c) {
        if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' ||
           c == 'u' || c == 'U')
            return true;
        return false;
        
    }
    string toGoatLatin(string sentence) {
        string res;
        istringstream is(sentence);
        string s;
        int cnt = 1;
        while (is >> s) {
            if (isVowel(s[0])) {
                s += "ma";
            } else {
                char tmp = s[0];
                s.erase(s.cbegin());
                s.push_back(tmp);
                s += "ma";
            }
            
            s += string(cnt, 'a');
            res += s;
            ++cnt;
            res += " ";
        }
        res.erase(--res.cend());
        return res;
    }
};

int main() {
  
  
  
  return 0;  
}

class Solution {
public:
    bool isVowel(const char &c) {
        return (c == 'a') || (c == 'A') || (c == 'e') || (c == 'E') || (c == 'I') || (c == 'i') || (c == 'o') || (c == 'O')
            || (c == 'u') || (c == 'U');
    }
    string sortVowels(string s) {
        vector<char> vowels;
        for (const auto &e: s) {
            if (isVowel(e)) {
                vowels.push_back(e);
            }
        }
        sort(vowels.begin(), vowels.end());  
        int start = 0;
        for (int i = 0; i != s.size(); ++i) {
            if (isVowel(s[i])) {
                s[i] = vowels[start];
                ++start;
            }
        }
        return s;
    }
};

int main() {



  return 0;
}

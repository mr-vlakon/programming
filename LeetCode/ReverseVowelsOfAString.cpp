class Solution {
public:
    bool isVowel(const char &c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' 
           || c == 'O' || c == 'U')
            return true;
        return false;
    }
    string reverseVowels(string s) {
        string vowels;
        for (const auto &e: s) {
            if (isVowel(e))
                vowels.push_back(e);
        }
        reverse(vowels.begin(), vowels.end());
        
        string result;
        int i = 0;
        for (const auto &e: s) {
            if (isVowel(e)) {
                result.push_back(vowels[i++]);
            } else {
                result.push_back(e);
            }
        }
        
        return result;
    }
};

int main() {
  
  
  
  return 0;  
}

class Solution {
public:
    bool isVowel(const char &c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }
    int countVowelSubstrings(string word) {
        int cnt = 0;
        for (int i = 0; i != word.size(); ++i) {
            unordered_map<int, int> um;
            bool status = true; 
            for (int j = i; j != word.size(); ++j) {
                if (!isVowel(word[j])) {
                    break;
                }
                if (um.size() == 5)
                    ++cnt;
                ++um[word[j]];
            }
            if (um.size() == 5) {
                ++cnt;
            }
            
        }
        return cnt;
    }
};

int main() {
  
  
  
  return 0;  
}

class Solution {
public:
    bool isVowel(const char &c) {
        return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'u') || (c == 'o');
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int answer = 0;
        for (int i = left; i <= right; ++i) {
            if (isVowel(words[i][0]) && isVowel(words[i].back())) {
                ++answer;
            }    
        }
        return answer;
    
    }
};

int main() {
  
  
  
  return 0;  
}

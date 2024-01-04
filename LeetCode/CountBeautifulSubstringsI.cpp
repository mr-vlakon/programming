class Solution {
public:
    bool isVowel(const char &c) {
        return (c == 'a') || (c == 'o') || (c == 'e') || (c == 'u') || (c == 'i');
    }
    int beautifulSubstrings(string s, int k) {
        int answer = 0;
        
        for (int i = 0; i != s.size(); ++i) {
            int vowel = 0;
            int conson = 0;
            for (int j = i; j != s.size(); ++j) {
                if (isVowel(s[j])) {
                    ++vowel;
                }
                else
                {
                    ++conson;
                }
                if (vowel == conson) {
                    if (((vowel*conson) % k == 0)) {
                        ++answer;
                    }
                }
            }
        }
        return answer;
    }
};

int main()
{


  return 0;
}

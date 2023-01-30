class Solution {
public:
    bool isVowel(const char &c) {
        return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
    }
    int maxVowels(string s, int k) {
        unordered_map<char, int> um;
        for (int i = 0; i != k; ++i) {
            if (isVowel(s[i])) {
                um[s[i]]++;
            }
        }
        int tmp = 0;
        for (const auto &e: um) {
            tmp += e.second;
        }
        int answer = tmp;
        for (int i = 1; i <= (s.size() - k); ++i) {
            if (um[s[i - 1]] != 0) {
                tmp--;
                um[s[i - 1]]--;
            }
            if (isVowel(s[i + k - 1])) {
                um[s[i + k - 1]]++;
                tmp++;
            } 
            if (tmp > answer) {
                answer = tmp;
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}

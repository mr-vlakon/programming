class Solution {
public:
    int countAsterisks(string s) {
        int cnt = 0;
        int answer = 0;
        for (int i = 0; i != s.size(); ++i) {
            if (cnt == 0 && s[i] == '*')
                ++answer;
            if (cnt == 2 && s[i] == '|') {
                cnt = 1;
            } else if (cnt == 2 && s[i] == '*') {
                    ++answer;
            } else if (cnt != 2 && s[i] == '|') {
                ++cnt;
            }    
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}

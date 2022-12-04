class Solution {
public:
    int minimumMoves(string s) {
        int cnt = 0;
        for (int i = 0; i != s.size(); ++i) {
            if (s[i] == 'X') {
                ++cnt;
                s[i] = 'O';
                if (i + 1 < s.size() && s[i + 1] == 'X') {
                    s[i + 1] = 'O';
                }
                if (i + 2 < s.size() && s[i + 2] == 'X') {
                    s[i + 2] = 'O';
                }
                
            }
        }
        return cnt;
    }
};

int main() {
  
  
  return 0;  
}

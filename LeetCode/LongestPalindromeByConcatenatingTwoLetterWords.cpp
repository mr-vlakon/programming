class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> um;
        for (const auto &e: words) {
            um[e]++;
        }
        int answer = 0;
        int rem = 0;
        string s(2, ' ');
        for (const auto &e: words) {
            s[0] = e[1];
            s[1] = e[0];
            if ((e[0] != e[1]) && um[s] >= 1 && um[e] >= 1) {
                um[e]--;
                um[s]--;
                answer += 4;
            } else if (e[0] == e[1]){
                if (um[e] == 1 && rem == 0) {
                    answer += 2;
                    um[e]--;
                    rem = 1;
                } else if ((um[e] % 2) == 0) {
                    answer += um[e]*2;
                    um[e] = 0;
                } else {
                    answer += (um[e] - 1)*2;
                    um[e] = 1;
                }
            }
        }
      return answer;
    }
};

int main() {
  
  
  
  
  return 0  
}

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> um;
        for (const auto &e: s) {
            um[e]++;
        }
        int maxOdd = 0;
        char c;
        for (const auto &e: um) {
            if ((e.second % 2) == 1) {
                maxOdd = max(maxOdd, e.second);
                
            }
        }
        for (const auto &e: um) {
            if (e.second == maxOdd) {
                c = e.first;
                break;
            }
        }
        int answer = maxOdd;
        for (const auto &e: um) {
            if ((e.second % 2) == 0) {
                answer += e.second;
            } else {
                if (e.first != c)
                    answer += e.second - 1;
            }
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}

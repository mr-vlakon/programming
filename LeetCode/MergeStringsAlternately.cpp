class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        deque<char> q1(word1.cbegin(), word1.cend());
        deque<char> q2(word2.cbegin(), word2.cend());
        string res;
        while (!q1.empty() || !q2.empty()) {
            if (q1.empty()) {
                res += string(q2.cbegin(), q2.cend());
                break;
            }
            if (q2.empty()) {
                res += string(q1.cbegin(), q1.cend());
                break;
            }
            char tmp = q1.front();
            res += tmp;
            q1.pop_front();
            
            tmp = q2.front();
            res += tmp;
            q2.pop_front();
        }
        return res;
    }
};

int main() {
  
  
  return 0;  
}

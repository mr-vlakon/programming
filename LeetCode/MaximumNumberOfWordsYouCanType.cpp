class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> us;
        for (const auto &e: brokenLetters) {
            us.insert(e);
        }
        istringstream is(text);
        string s;
        int cnt = 0;
        while (is >> s) {
            for (const auto &e: s) {
                if (us.find(e) != us.cend()) {
                    --cnt;
                    break;
                }
            }
            
            ++cnt;
        }
        
        return cnt;
    }
};

int main() {
  
  
  return 0;  
}

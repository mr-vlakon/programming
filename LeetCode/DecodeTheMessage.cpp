class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> um;
        int i = 0;
        for (const auto &e: key) {
            if (e != ' ' && um.find(e) == um.cend()) {
                um[e] = 'a' + i;
                ++i;
            }
        }
        
        string res;
        for (const auto &e: message) {
            if (e != ' ')
                res += um[e];
            else {
                res += ' ';
            }
        }
        return res;
        
    }
};

int main() {
  
  
  return 0;  
}

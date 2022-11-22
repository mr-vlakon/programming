class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> um;
        for (const auto &e: s) {
            ++um[e];
        }
        int cnt = 0;
        while(true) {
            for (const auto &e: target) {
                auto it = um.find(e);
                if (it == um.cend())
                    return 0;
                if (it->second != 0) {
                    --(it->second);
                } else {
                    return cnt;
                }
            }
            ++cnt;
        }
        return 0;      
    }
};

int main() {
  
  
  
  return 0;  
}

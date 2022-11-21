class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> us(allowed.cbegin(), allowed.cend());
        int cnt = 0;
        for (const auto &e: words) {
            bool status = true;
            for (const auto &p : e) {
                if (us.find(p) == us.cend()) {
                    status = false;
                    break;
                }
            }
            if (status)
                ++cnt;
        }
        return cnt;
    }
};

int main() {
  
  
  
  return 0;  
}

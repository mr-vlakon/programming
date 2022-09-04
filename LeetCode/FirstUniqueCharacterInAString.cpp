class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, size_t> um;
        for (const auto &e: s) {
            ++um[e];
        }
        int index = 0;
        for (const auto &e : s) {
            auto it = um.find(e);
            if (it != um.cend()) {
                if(it->second == 1)
                    return index; 
            }
            ++index;
        }
        return -1;
    }
};

int main() {
  
  
  return 0;  
}

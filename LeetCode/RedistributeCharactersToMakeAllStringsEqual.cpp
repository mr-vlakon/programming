class Solution {
public:
    bool makeEqual(vector<string>& words) {
        if (words.size() == 1) return true;
        int size = words.size();
        
        unordered_map<char, size_t> um;
        for (const auto &e: words) {
            for (const auto &p: e)
                ++um[p];
        }
        for (const auto &e: um) {
            if (e.second % size != 0)
                return false;
        }
        return true;
    }
};

int main() {
  
  
  
  return 0;  
}

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int result = 0;
        unordered_map<char, size_t> umap;
        for (const auto &ch: chars) {
            ++umap[ch];
        }
        for (const auto &e: words) {
            unordered_map<char, size_t> um;
            for (const auto &c: e) {
                ++um[c];
            }
            bool status = true;

            for (const auto &k: um) {
                auto it = umap.find(k.first);
                if (it == umap.cend()) {
                    status = false;
                    break;
                } else {
                    if (k.second > it->second) {
                        status = false;
                        break;
                    }
                }
            }            
            if (status)
                result += e.size();
        }
        return result;
    }
};

int main() {
  
  
  return 0;  
}

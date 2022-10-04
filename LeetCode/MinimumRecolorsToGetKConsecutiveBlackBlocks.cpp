class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        vector<int> v;
        for (decltype(blocks.size()) i = 0; i <= blocks.size() - k; ++i) {
            string tmp(blocks.cbegin() + i, blocks.cbegin() + i + k);
            v.push_back(count(tmp.cbegin(), tmp.cend(), 'W'));
        }
        
        
        return *min_element(v.cbegin(), v.cend());
    }
};

int main() {
  
  
  return 0;  
}

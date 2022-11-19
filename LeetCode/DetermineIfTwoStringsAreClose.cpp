class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        unordered_map<char, int> um1;
        unordered_map<char, int> um2;
        for (int i = 0; i != word1.size(); ++i) {
            ++um1[word1[i]];
            ++um2[word2[i]];
        }
        vector<int> v1;
        vector<int> v2;
        for (const auto &e: um1) {
            auto it = um2.find(e.first);
            if (it == um2.cend()) return false;
            v1.push_back(e.second);
        }
        for (const auto &e: um2) {
            v2.push_back(e.second);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return v1 == v2;
    }
};

int main() {
  
  
  return 0;  
}

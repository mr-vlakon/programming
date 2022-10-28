class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //sort(strs.begin(), strs.end());

        vector<pair<string, string>> v;
        
        for (const auto &e: strs) {
            v.push_back({e, e});
        }
        
        for (auto &e: v) {
            sort(e.first.begin(), e.first.end());
        }
        
        unordered_map<string, vector<string>> um;
        
        for (const auto &e: v) {
            um[e.first].push_back(e.second);
        }
        
        vector<vector<string>> res;
        
        for (const auto &e: um) {
            res.push_back(e.second);
        }        
        
        return res;
    }
};

int main() {
  
  
  return 0;  
}

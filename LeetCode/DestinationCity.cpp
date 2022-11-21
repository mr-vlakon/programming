class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> um;
        for (const auto &e: paths) {
            um[e[0]]++;
            um[e[1]]++;
        }
        
        vector<string> v;
        for (const auto &e: um) {
            if (e.second == 1) {
                v.push_back(e.first);
            }
        }
        for (const auto &e: paths) {
            if (v[0] == e[1] || v[1] == e[1]) {
                return e[1];
            }
        }
        return "";
    }
};

int main() {
  
  
  return 0;  
}

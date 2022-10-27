class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<size_t, map<string, size_t> > um;
        
        for (const auto &e: orders) {
            ++um[stoi(e[1])][e[2]];
        }
        
        for (auto &e: um) {
            for (const auto &p: orders) {
                e.second[p[2]];
            }
        }
        
        vector<vector<string>> v(um.size() + 1);
        v[0].push_back("Table");
        auto beg = um.begin()->second;
        
        for (const auto &p : beg) {
            v[0].push_back(p.first);
        }
        
        int i = 1;
        for (const auto &e: um) {
            v[i].push_back(to_string(e.first));
            for (const auto &p: e.second) {
                v[i].push_back(to_string(p.second));
            }
            ++i;
        }
        return v;
    }
};

int main() {
  
    
  return 0; 
}

class Solution {
public:
    int countPoints(string rings) {
        unordered_map<char, unordered_set<char>> us;
        
        for (decltype(rings.size()) i = 1; i < rings.size(); i += 2) {
            us[rings[i]].insert(rings[i - 1]);    
        }
        int cnt = 0;
        for (const auto &e :us) {
            if (e.second.size() == 3) {
                ++cnt;
            }
        }
        return cnt;
        
    }
};

int main() {
  
  
  return 0;  
}

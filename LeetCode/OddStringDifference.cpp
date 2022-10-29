class Solution {
public:
    string oddString(vector<string>& words) {
        vector<pair<vector<int>, string>> v;
        for (const auto &e: words) {
            vector<int> tmp;
            for (decltype(e.size()) i = 0; i != e.size() - 1; ++i) {
                tmp.push_back(e[i + 1] - e[i]);
            }
            v.push_back({tmp, e});
        }
        vector<int> first = v[0].first;
        
        auto cnt = count_if(v.cbegin(), v.cend(), [=] (const pair<vector<int>, string> &lhs) {
            return lhs.first == first;
        });
        
        if (cnt == 1) {
            return v[0].second;
        }
        for (const auto &e: v) {
            if (e.first != first)
                return e.second;
        }
        
        return "";
                
    }
};

int main() {
  
  
  
  
  return 0;  
}

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, pair<string, string>>> v;
        for (int i = 0; i != indices.size(); ++i) {
            v.push_back({indices[i], {sources[i], targets[i]}});
        }
        sort(v.begin(), v.end(), [](pair<int, pair<string, string>> &lhs, pair<int, 
        pair<string, string>> &rhs) {
            return lhs.first < rhs.first;
        });
        vector<pair<int, pair<string, string>>> ind;
        for (int i = 0; i != v.size(); ++i) {
            if (string{s.cbegin() + v[i].first, s.cbegin() + v[i].first + v[i].second.first.size() } == v[i].second.first
            ) {
                ind.push_back({v[i].first, v[i].second});
            }
        }
        string answer;
        int offset = 0;
        size_t pos = 0;
        for (int i = 0; i != ind.size(); ++i) {
            pos = ind[i].first + offset;
            offset += ind[i].second.second.size() - ind[i].second.first.size();
            s.replace(pos, ind[i].second.first.size(), ind[i].second.second);
        }
        return s;
    }
};

int main() {
  
  
  
  
  return 0;  
}

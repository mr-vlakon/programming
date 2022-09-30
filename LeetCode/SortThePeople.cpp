class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string, int>> v;
        for (decltype(names.size()) i = 0; i != names.size(); ++i) {
            v.push_back({names[i], heights[i]});
        }
        sort(v.begin(), v.end(), 
             [=] (const pair<string, int> &lhs, const pair<string, int> &rhs) {
                return lhs.second > rhs.second; 
             });
        vector<string> res;
        for (const auto &e: v) {
            res.push_back(e.first);
        }
        return res;
    }
};

int main() {
  
  return 0;  
}

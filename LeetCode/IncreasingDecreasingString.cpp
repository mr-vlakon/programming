class Solution {
public:
    string sortString(string s) {
        unordered_map<char, int> um;
        for (const auto &e: s) {
            um[e]++;
        }
        vector<pair<char, int>> v;
        for (const auto &e: um) {
            v.push_back({e.first, e.second});
        }
        sort(v.begin(), v.end(), [] (pair<char, int> &lhs, pair<char, int> &rhs) {
            return lhs.first < rhs.first;
        });
        string answer;
        int cnt = 0;
        while (cnt != v.size()) {
            for (int i = 0; i != v.size(); ++i) {
                --v[i].second;
                if (v[i].second == 0) {
                    answer.push_back(v[i].first);
                    ++cnt;
                } else if (v[i].second > 0) {
                    answer.push_back(v[i].first);
                }
            }
            for (int i = v.size() - 1; i >= 0; --i) {
                --v[i].second;
                if (v[i].second == 0) {
                    answer.push_back(v[i].first);
                    ++cnt;
                } else if (v[i].second > 0) {
                    answer.push_back(v[i].first);
                }
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}

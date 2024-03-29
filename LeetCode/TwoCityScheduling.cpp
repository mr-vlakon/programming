class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int, int>> v;
        for (const auto &e: costs) {
            v.push_back({e[0] - e[1], e[0]});
        }
        sort(v.begin(), v.end(), [] (pair<int, int> &lhs, pair<int, int> &rhs) {
            return lhs.first < rhs.first;
        });
        int cnt = 0;
        int answer = 0;
        for (int i = 0; i != v.size(); i++) {
            if (cnt < (v.size() / 2)) {
                answer += v[i].second;
            } else {
                answer += v[i].second - v[i].first;
            }
            ++cnt;
        }
        return answer;

    }
};

int main() {
  
  
  
  return 0;  
}

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> um;
        for (const auto &e: nums) ++um[e];
        vector<pair<int, int>> v;
        for (const auto &e: um) {
            v.push_back({e.first, e.second});
        }
        sort(v.begin(), v.end(), [](pair<int, int> &lhs, pair<int, int> &rhs) {
            return lhs.first < rhs.first;
        });
        int prevF = 0;
        int prevS = v[0].first*v[0].second;
        int answer = prevS;  
        int take = v[0].first;
        for (int i = 1; i != v.size(); ++i) {
            if ((v[i].first - v[i - 1].first) == 1) {
                answer = max(prevF + v[i].first*v[i].second, answer);
            } else {
                answer = max(prevS + v[i].first*v[i].second, answer);
            }
            prevF = prevS;
            prevS = answer;
        }
        return answer;
    }
};

int main() {



  return 0;
}

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> v;
        for (int i = 0; i != scores.size(); ++i) {
            v.push_back({ages[i], scores[i]});
        }
        sort(v.begin(), v.end(), [](pair<int, int> &lhs, pair<int, int> &rhs) {
            return lhs.second > rhs.second;
        });
        stable_sort(v.begin(), v.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
            return lhs.first > rhs.first;
        });
        vector<int> dp(scores.size(), 0);
        vector<int> dpM(scores.size(), 0);
        dp[0] = v[0].second;
        dpM[0] = v[0].second;
        int tmp = 0;
        int minV = 0;
        for (int i = 1; i != scores.size(); ++i) {
            tmp = v[i].second;
            minV = INT_MAX;
            for (int j = 0; j < i; ++j) {
                if (dpM[j] >= v[i].second && tmp < (dp[j] + v[i].second)) {
                    tmp = max(tmp, dp[j] + v[i].second);
                    minV = dpM[j];
                }
            }
            dp[i] = tmp;
            dpM[i] = min(minV, v[i].second);
        }      
        return *max_element(dp.cbegin(), dp.cend());
    }
};

int main() {
  
  
  
  
  return 0;  
}

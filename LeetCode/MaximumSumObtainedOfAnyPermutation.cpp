class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        sort(nums.begin(), nums.end());
        vector<int> pref(nums.size(), 0);
        for (const auto &e: requests) {
            if ((e[0] - 1) >= 0) {
                pref[e[0] - 1]--;
            }
            pref[e[1]]++;
        }
        for (int i = pref.size() - 2; i >= 0; --i) {
            pref[i] += pref[i + 1];
        }
        sort(pref.begin(), pref.end());
        int answer = 0;
        for (int i = 0; i != pref.size(); ++i) {
            answer += static_cast<long long>(pref[i])*nums[i] % 1000000007;
            answer %= 1000000007;
        }
        return answer % 1000000007;
    }
};

int main() {
  
  
  
  return 0;  
}

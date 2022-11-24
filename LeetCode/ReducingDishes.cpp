class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        vector<pair<long long, long long>> dp(satisfaction.size(), {0, 0});
        long long sum = accumulate(satisfaction.cbegin(), satisfaction.cend(), 0LL);
        long long tmp = 0;
        for (int i = 0; i != satisfaction.size(); ++i) {
            tmp += static_cast<long long>(i + 1) * 
                static_cast<long long>(satisfaction[i]);
        }
        dp[0] = {sum, tmp};
        int max = std::max(0, static_cast<int>(tmp));
        for (int i = 1; i != satisfaction.size(); ++i) {
            int currSum = dp[i - 1].first - satisfaction[i - 1];
            int x = dp[i - 1].second - satisfaction[i - 1];
            dp[i] = {currSum , x - currSum};
            if (x - currSum > max)
                max = x - currSum;
        }
        return max;
    }
};

int main() {
  
  
  
  return 0;  
}

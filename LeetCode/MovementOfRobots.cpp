class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int tmp = 0;
        vector<long long> num(nums.cbegin(), nums.cend());
        for (int i = 0; i != num.size(); ++i) {
            if (s[i] == 'R') {
                num[i] += d;
            } else {
                num[i] -= d;
            }
        }
        sort(num.begin(), num.end());
        int tt = abs(num[0]);
        if (num[0] < 0) {
            for (int i = 0; i != num.size(); ++i) {
                num[i] += tt;
            }
        } else {
            for (int i = 0; i != num.size(); ++i) {
                num[i] -= tt;
            }
        }
        long long x = accumulate(num.cbegin(), num.cend(), 0LL);
        long long ans = x;
        for (int i = 1; i != num.size(); ++i) {
            x -= static_cast<long long>(num.size() - i)*static_cast<long long>(num[i] - num[i - 1]); 
            ans += x;
            ans %= 1000000007;
        }
        return ans % 1000000007;
    }
};

int main() {
  
  
  
  return 0;  
}

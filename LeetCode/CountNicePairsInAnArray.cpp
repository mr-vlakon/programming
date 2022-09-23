class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        vector<int> tmp;
        int i = 0;
        while (i != nums.size()) {
            int rev = 0;
            int x = nums[i];
            while (x) {
                rev = (rev * 10) + (x % 10);
                x /= 10;
            }
            tmp.push_back(nums[i] - rev);
            ++i;
        }
        unordered_map<int, size_t> um;
        for (const auto &e: tmp) {
            ++um[e];
        }
        int cnt = 0;
        for (const auto &e: um) {
            if (e.second >= 2) {
                int t = e.second - 1;
                while (t) {
                    cnt += t;
                    --t;
                    if (cnt > 1000000000)
                        cnt %= 1000000007;
                }
            }
        }
        return cnt;        
    }
};

int main() {
  
  
  return 0;  
}

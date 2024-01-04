class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        if ((k == nums.size()))
        {
            int x = nums[0];
            for (int i = 1; i != nums.size(); ++i) {
                x &= nums[i];
            }
            return x;
        } else if (k == 1) {
            int x = nums[0];
            for (int i = 1; i != nums.size(); ++i) {
                x |= nums[i];
            }
            return x;
        }
        vector<vector<int>> v(nums.size());
        for (auto &e: v) {
            e.resize(32, 0);
        }
        for (int i = 0; i != nums.size(); ++i) {
            int tmp = nums[i];
            int k = 0;
            while (tmp) {
                v[i][k] += (tmp % 2);
                tmp /= 2;
                ++k;
            }
            
        }
        int counter = 0;
        int answer = 0;
        for (int i = 0; i != 32; ++i) {
            counter = 0;
            for (const auto &e: v) {
                if (e[i] == 1) {
                    ++counter;
                }
            }
            if (counter >= k) {
                answer += pow(2, i);
            }
        }
        return answer;
    }
};

int main()
{



  return 0;
}

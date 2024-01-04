class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxEl = *max_element(nums.cbegin(), nums.cend());
        vector<int> posAp;
        long long answer = 0;
        for (int i = 0; i != nums.size(); ++i) {
            if (nums[i] == maxEl) {
                posAp.push_back(i);
            }
            if (posAp.size() >= k) {
                int tmp = posAp[posAp.size() - k];
                answer += tmp + 1;
            }
        }
        return answer;
    }
};

int main()
{


  return 0;
}

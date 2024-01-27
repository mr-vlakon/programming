class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int answer = nums[0];
        int minV = INT_MAX;
        for (int i = 1; i != nums.size() - 1; ++i)
        {
            for (int j = i + 1; j != nums.size(); ++j)
            {
                minV = min(minV, nums[i] + nums[j]);
            }
        }
        return answer + minV;
    }
};

int main()
{

  return 0;
}

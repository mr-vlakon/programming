class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int answer = 0;
        vector<bool> numsB(51, 0);
        for (const auto &e: nums)
        {
            numsB[e] = true;
        }
        int tmp = nums[0];
        for (int i = 1; i != nums.size(); ++i)
        {
            if (nums[i] == (nums[i - 1] + 1))
            {
                tmp += nums[i];
            }
            else
            {
                break;
            }
        }
        
        int start = tmp;
        while (start != INT_MAX)
        {
            if (start < numsB.size() && numsB[start] == false)
            {
                return start;
            }
            else if (start >= numsB.size())
            {
                return start;
            }
            ++start;
        }
        
        return 0;
        
    }
};

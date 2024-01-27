class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int answer = nums.size();
        int start = 0;
        int end = nums.size() - 1;
        while (start < end)
        {
            if (nums[start] == 0)
            {
                ++start;
            }
            if (((nums[end] % nums[start]) != nums[start]) && ((nums[end] % nums[start]) != 0))
            {
                nums[start] = (nums[end] % nums[start]);
                --end;
            }
            else if ((nums[start] % nums[end]) != 0)
            {
                --end;
            }
            else
            {
                ++start;
                --end;
            }
            --answer;
        }
        return answer;
    }
};

int main()
{


  return 0;
}

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long answer = nums[0] + nums[1];
        bool flag = false;
        long long ans = nums[0] + nums[1];
        for (int i = 2; i != nums.size(); ++i) {
            if (nums[i] >= answer) 
            {
                answer += nums[i];
            }
            else 
            {
                answer += nums[i];
                flag = true;
                ans = answer;
            }
        }
        return (flag == false) ? -1 : ans;
    }
};

int main()
{


  return 0;
}


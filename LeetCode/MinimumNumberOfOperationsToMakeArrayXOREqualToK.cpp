class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int start = nums[0];
        for (int i = 1; i != nums.size(); ++i)
        {
            start ^= nums[i];
        }
        start ^= k;
        int count = 0;
        while (start)
        {
            count += start % 2;
            start /= 2;
        }
        return count;
    }
};

int main()
{

  return 0;
}

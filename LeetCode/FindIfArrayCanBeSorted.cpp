class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        if (is_sorted(nums.cbegin(), nums.cend())) return true;
        vector<int> tmpV(257, 0);
        for (int i = 1; i != tmpV.size(); ++i)
        {
            int tmpVal = i;
            int cntBit = 0;
            while (tmpVal)
            {
                cntBit += (tmpVal % 2);
                tmpVal /= 2;
            }
            tmpV[i] = cntBit;
        }
        for (int i = 0; i != nums.size(); ++i)
        {
            int ind = i;
            for (int j = 0; j != nums.size() - 1; ++j)
            {
                if (nums[j] > nums[j + 1])
                {
                    if (tmpV[nums[j]] != tmpV[nums[j + 1]])
                    {
                        return false;
                    }
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        return true;
    }
};

int main()
{


  return 0;
}

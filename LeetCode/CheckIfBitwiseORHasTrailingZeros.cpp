class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        vector<string> str;
        int tmp = 0;
        string s;
        for (int i = 0; i != nums.size(); ++i) {
            tmp = nums[i];
            s = "";
            while(nums[i])
            {
                s.push_back((nums[i] % 2) + '0');
                nums[i] /= 2;
            }
            str.push_back(s);
        }
        
        bool flag = false;
        int count1 = 0;
        int count0 = 0;
        for (const auto &e: str) {
            if (e[0] == '0')
            {
                ++count0;
            }
        }
        if (count0 > 1) {
            return true;
        }
        return false;
    }
};

int main()
{



  return 0;
}

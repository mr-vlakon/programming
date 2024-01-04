class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        for (int i = 0; i != nums.size(); i += 3){
            if ((nums[i + 2] - nums[i]) <= k) {
                vector<int> tmp{nums[i], nums[i + 1], nums[i + 2]};
                answer.push_back(tmp);
            }
            else
            {
                return {};
            }
        }
        if (answer.size() != (nums.size() / 3)) return {};
        return answer;
    }
};

int main()
{


  return 0;
}

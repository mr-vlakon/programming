class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int absDiff = 0;
        int absInd = 0;
        for (int i = 0; i != nums.size(); ++i) {
            for (int j = i; j != nums.size(); ++j) {
                if ((abs(nums[i] - nums[j]) >= valueDifference) && (abs(i - j) >= indexDifference)) {
                    return vector<int>{i, j};
                }
            }
        }
        return vector<int>{-1, -1};
    }
    
};

int main()
{


  return 0;
}

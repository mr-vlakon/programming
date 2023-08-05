class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> us;
        for (const auto &e: nums) us.insert(e);
        int distinctAll = us.size();
        int answer = 0;
        us.clear();
        for (int i = 0; i != nums.size(); ++i) {
            for (int j = i; j != nums.size(); ++j) {
                us.insert(nums[j]);
                if (us.size() == distinctAll) ++answer;
            
            }
            us.clear();
        }
        return answer;
    }
};

int main() {



  return 0;
}

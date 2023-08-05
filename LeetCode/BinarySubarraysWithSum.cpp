class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int> um(count(nums.cbegin(), nums.cend(), 1) + 1, 0);
        int pref = 0;
        int answer = 0;
        um[0] = 1;
        int prevS = 0;
        for (int i = 0; i != nums.size(); ++i) {
            pref += nums[i];
            if ((pref - goal) >= 0 && um[pref - goal] != 0) {
                answer += um[pref - goal];
            }
            if (pref == prevS) {
                ++um[pref];
            } else {
                um[pref] = 1;
            }
            prevS = pref;
        }
        return answer;
    }
};

int main() {




  return 0;
}

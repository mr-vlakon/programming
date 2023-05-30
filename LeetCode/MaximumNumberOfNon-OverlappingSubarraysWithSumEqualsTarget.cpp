class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        int pref = 0;
        um[0] = 1;
        int answer = 0;
        unordered_map<int, int>::iterator it;
        for (int i = 0; i != nums.size(); ++i) {
            pref += nums[i];
            it = um.find(pref - target);
            if (it != um.cend()) {
                ++answer;
                um.clear();
                um[0] = 1;
                pref = 0;
            } else {
                um[pref]++;
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}

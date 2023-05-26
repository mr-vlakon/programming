class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int pref = 0;
        um[0] = 1;
        int answer = 0;
        unordered_map<int, int>::iterator it;
        for (int i = 0; i != nums.size(); ++i) {
            pref += nums[i];
            it = um.find(pref - k);
            if (it != um.cend()) {
                answer += it->second;
            }
            um[pref]++;
        }
        return answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}

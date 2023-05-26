class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int pref = 0;
        int answer = 0;
        vector<int> v(k + 1, 0);
        v[0] = 1;
        for (int i = 0; i != nums.size(); ++i) {
            pref += nums[i];
            pref %= k;
            if (pref >= 0) {
                answer += v[pref];
                ++v[pref];
            } else {
                answer += v[pref + k];
                ++v[pref + k];
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}

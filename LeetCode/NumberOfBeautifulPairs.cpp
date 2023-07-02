class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        int answer = 0;
        for (int i = 0; i != nums.size() - 1; ++i) {
            for (int j = i + 1; j != nums.size(); ++j) {
                if (i != j) {
                string s1 = to_string(nums[i]);
                string s2 = to_string(nums[j]);
                if (gcd(s1[0] - '0',s2.back() - '0') == 1) {
                    answer += 1;
                }
                }
            }
        }
        return answer;
    }
};

int main() {

  
  return 0;
}

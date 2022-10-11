class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int sum = 0;
        for (const auto &e: nums) {
            sum += e;
            ans.push_back(sum);
        }
        return ans;
    }
};

int main() {
  
  
  return 0;  
}

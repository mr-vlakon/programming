class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> um;
        vector<int> sums(nums.size(), 0);
        int sum = 0;
        int answer = 0;
        int ind = -1;
        unordered_map<int, int>::iterator it;
        for (int i = 0; i != nums.size(); ++i) {
            it = um.find(nums[i]);
            sum += nums[i];
            if (it == um.cend()) {
                if (ind == -1) {
                    answer = max(answer, sum);
                } else {
                    answer = max(answer, sum - sums[ind]);
                }
            } else {
                ind = max(ind, um[nums[i]]);
                answer = max(answer, sum - sums[ind]);
            }
            um[nums[i]] = i; 
            sums[i] = sum;
        }
        return answer;
    }
};

int main() {



  return 0;
}

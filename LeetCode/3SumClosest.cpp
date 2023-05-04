class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int start = 0;
        int end = 0;
        int answer = 0;
        int minDif = INT_MAX;
        int tmp = 0;
        int sum = 0;
        for (int i = 0; i != nums.size() - 2; ++i) {
            start = i + 1;
            end = nums.size() - 1;
            while (start < end) {
                sum = nums[i] + nums[start] + nums[end];
                tmp = abs(target - sum);
                if (sum == target) return sum;
                if (minDif >= tmp) {
                    answer = sum;
                    minDif = tmp;
                }
                if (sum >= target) {
                    --end;
                } else {
                    ++start;
                }
            }
            if (minDif == 0) return answer;
        }
        return answer;  
    }
};

int main() {
  
  
  
  
  return 0;  
}

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int answer = 1;
        int startRInd = 0;
        for (int i = 1; i != nums.size(); ++i) {
            if ((nums[i] - nums[0]) <= (2*k)) {
                ++answer;
            } else {
                startRInd = i;
                break;
            }
        }
        int startLInd = 0;
        int left = nums[0];
        int tmp = answer;
        for (int i = nums[0]; i <= (nums.back() - 2*k); ++i) {
            while (startRInd < nums.size() && nums[startRInd] == (i + 2*k)) {
                ++tmp;
                ++startRInd;
            }
            answer = max(answer, tmp);
            while (startLInd < nums.size() && nums[startLInd] == i) {
                ++startLInd;
                --tmp;
            }
        }
        return answer;
    }
};

int main() {

  
  return 0;
}

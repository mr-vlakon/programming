class Solution {
public:
    void binary(const vector<int> &nums, const int &target, int &left, int &right) {
        if (left > right) return;
        mid = (left + right) / 2;
        tmpS = 0;
        tmp = 0;
        for (int i = 0; i != mid; ++i) {
            tmpS += nums[i]; 
        }
        tmp = max(tmpS, tmp);
        for (int i = 1; i != nums.size() - mid + 1; ++i) {
            tmpS -= nums[i - 1];
            tmpS += nums[i + mid - 1];
            tmp = max(tmpS, tmp);
        }
        if (tmp >= target) {
            answer = min(answer, mid);
            right = mid - 1;
            binary(nums, target, left, right);
        } else {
            left = mid + 1;
            binary(nums, target, left, right);
        }

    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = nums.size();
        binary(nums, target, left, right);
        if (answer == 1000000000) return 0;
        return answer;
    }
private:
    int mid = 0;
    int tmpS = 0;
    int tmp = 0;
    int answer = 1000000000;
};

int main() {
  
  
  
  return 0;  
}

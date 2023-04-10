class Solution {
public:
    void binary(const vector<int> &nums, const int &target, int &left, int &right) {
        if (left > right) return;
        mid = (left + right) / 2;
        if (nums[mid] == target) {
            answer = mid;
        } else if (nums[mid] < nums[right] && target <= nums[right] && target > nums[mid]) {
            left = mid + 1;
            binary(nums, target, left, right);
        } else if (nums[mid] > nums[left] && target >= nums[left] && target < nums[mid]) {
            right = mid - 1;
            binary(nums, target, left, right);
        } else if (nums[right] < nums[mid] && (target > nums[mid] || target <= nums[right])) {
            left = mid + 1;
            binary(nums, target, left, right);
        } else  {
            right = mid - 1;
            binary(nums, target, left, right);
        }
    }
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        binary(nums, target, left, right);
        return answer;
    }
private:
    int answer = -1;
    int mid = 0;
};

int main() {
  
 return 0; 
}

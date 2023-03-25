class Solution {
public:
    void binary(const vector<int> &nums, int &left, int &right) {
        if (left > right) return;
        mid = (left + right) / 2;
        if ((mid - 1) >= 0 && (mid + 1) < nums.size()) {
            if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1]) {
                answer = nums[mid];
                return;
            } else {
                if ((mid + 1) < nums.size() && nums[mid + 1] == nums[mid]) {
                    if ((nums.size() - (mid + 1)) % 2 == 1) {
                        right = mid - 1;
                        binary(nums, left, right);
                        return;
                    } else {
                        left = mid + 1;
                        binary(nums, left, right);
                        return;
                    }
                } else if ((mid - 1) >= 0 && nums[mid - 1] == nums[mid]){
                    if ((mid - 1) % 2 == 1) {
                        right = mid - 1;
                        binary(nums, left, right);
                        return;
                    
                    } else {
                        left = mid + 1;
                        binary(nums, left, right);
                        return;
                    }
                }
                
            }
        } else {
            answer = nums[mid];
            return;
        }
    }
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        binary(nums, left, right);
        return answer;
    }
private:
    int mid = 0;
    int answer = 0;
};

int main() {
  
  return 0;  
}

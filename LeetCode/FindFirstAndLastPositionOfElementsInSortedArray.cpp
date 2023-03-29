/*
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto p = equal_range(nums.cbegin(), nums.cend(), target);
        int indx1 = p.first - nums.cbegin();
        int indx2 = p.second - nums.cbegin();
        if (indx1 == indx2)
            return {-1,-1};
        else
            return {indx1, --indx2};
    }
};
*/
class Solution {
public:
    void binaryLeft(const vector<int> &nums, const int &tar, int &left, int &right) {
        if (left > right) {
            return;
        }
        mid = (left + right) / 2;
        if (nums[mid] > tar) {
            right = mid - 1;
            binaryLeft(nums, tar, left, right);
        } else if (nums[mid] < tar){
            left = mid + 1;
            binaryLeft(nums, tar, left, right);
        } else if (nums[mid] == tar) {
            start = mid;
            right = mid - 1;
            binaryLeft(nums, tar, left, right);
        }
    }
    void binaryRight(const vector<int> &nums, const int &tar, int &left, int &right) {
        if (left > right) {
            return;
        }
        mid = (left + right) / 2;
        if (nums[mid] > tar) {
            right = mid - 1;
            binaryRight(nums, tar, left, right);
        } else if (nums[mid] < tar){
            left = mid + 1;
            binaryRight(nums, tar, left, right);
        } else if (nums[mid] == tar) {
            end = mid;
            left = mid + 1;
            binaryRight(nums, tar, left, right);
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        binaryLeft(nums, target, left, right);
        left = 0;
        right = nums.size() - 1;
        binaryRight(nums, target, left, right);
        return {start, end};
    }
private:
    int end = -1;        
    int start = -1;
    int mid = 0;
};

int main() {
  
  return 0;
}

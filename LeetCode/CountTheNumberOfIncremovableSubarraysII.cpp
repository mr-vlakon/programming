class Solution {
public:
    void binary_search(const vector<int> &nums, const int &val, int &left, int &right) {
        if (left > right) return;
        mid = (left + right) / 2;
        if (nums[mid] < val) {
            ind = mid;
            left = mid + 1;
            binary_search(nums, val, left, right);
        }
        else
        {
            right = mid - 1;
            binary_search(nums, val, left, right);        
        }
    }
    
    long long incremovableSubarrayCount(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        long long answer = 0;
        vector<bool> left(nums.size(), false);
        vector<bool> right(nums.size(), false);
        left[0] = true;
        right.back() = true;
        for (int i = 1; i != nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) 
            {
                left[i] = true;
            }
            else
            {
                break;
            }
        }
        for (int i = (nums.size() - 2); i >= 0; --i) {
            if (nums[i] < nums[i + 1]) 
            {
                right[i] = true;
            }
            else
            {
                break;
            }
        }

        int indLastSortedLeft = 0;
        ind = -1;
        int leftV = 0;
        int rightV = 0;
        for (int i = 0; i != (nums.size() - 1); ++i) {
            if (left[i] == true) {
                indLastSortedLeft = i;
            }
            leftV = 0;
            rightV = indLastSortedLeft;
            binary_search(nums, nums[i + 1], leftV, rightV);
            if (right[i + 1])
            {
                if (i != ind)
                {
                    answer += ind + 2;
                }
                else
                {
                    if (ind != -1)
                        answer += ind + 1;
                    else
                        answer += 1;
                }
            }
            ind = -1;
        }
        if (left.back()) {
            indLastSortedLeft = nums.size() - 1;
        }
        if (indLastSortedLeft != (nums.size() - 1))
        {
            answer += indLastSortedLeft + 2;
        }
        else
        {
            answer += indLastSortedLeft + 1;
        }
        return answer;        
    }
private:
    int ind = -1;
    int mid = 0;
};

int main()
{



  return 0;
}

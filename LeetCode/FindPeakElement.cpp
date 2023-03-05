class Solution {
public:
    void recursive(const vector<int> &num, int &start, int &end, int &mid) {
        if (mid > 0 && mid < (num.size() - 1) && num[mid] > num[mid - 1] && num[mid] > num[mid + 1]) {
            answer = mid;
            return;
        }
        if (mid == 0 && num[mid] > num[mid + 1]) {
            answer = mid;
            return;
        }
        if (mid == (num.size() - 1) && num[mid] > num[mid - 1]) {
            answer = mid;
            return;
        }
        if (start >= end) {
            return;
        }
        if ((mid + 1) < num.size() && num[mid] < num[mid + 1]) {
            start = mid + 1;
            mid = (start + end) / 2;
            recursive(num, start, end, mid);
        } else if ((mid - 1) >= 0 && num[mid] < num[mid - 1]) {
            end = mid - 1;
            mid = (start + end) / 2;
            recursive(num, start, end, mid);
        }
    }
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int start = 0;
        int end = nums.size() - 1;
        int mid = nums.size() / 2;
        recursive(nums, start, end, mid);
        return answer;
    }
private:
    int answer = 0;
};

/*
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums.size() == 2) {
            if (nums[0] < nums[1]) return 1;
        }
        if (nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;

        vector<pair<int,size_t>> res;
        for (decltype(nums.size()) i = 0; i != nums.size(); ++i) {
            res.push_back({nums[i], i});
        } 
        
        size_t index = 1;
        auto it = find_if(res.cbegin() + 1, res.cend() - 2,[&] 
                          (const pair<int, size_t> &x) {
            int tmp = index;
            ++index;
            return (nums[tmp - 1] < x.first) && (x.first > nums[tmp + 1]);
        });
        return it->second;
    }
};
*/

int main() {
  
  
  return 0;  
}

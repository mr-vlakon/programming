class Solution {
public:
    void binary(const vector<int> &nums, const int &p, int &left, int &right) {
        if (left > right) return;
        mid = (left + right) / 2;
        cnt = 0;
        taken = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (abs(nums[i] - taken) <= mid) {
                ++cnt;
                if (cnt >= p) break;
                if ((i + 1) < nums.size())
                    taken = nums[i + 1];
                ++i;
            } else {
                taken = nums[i];
            }
        } 
        if (cnt < p) {
            left = mid + 1;
            binary(nums, p, left, right);
        } else {
            answer = min(answer, mid);
            right = mid - 1;
            binary(nums, p, left, right);
        }
    }
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0;
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = max(nums.back() - nums[p - 1], nums[nums.size() - 1 - p] - nums[0]);
        binary(nums, p, left, right);
        return answer;
    }
private:
    int taken = 0;
    int cnt = 0;
    int mid = 0;
    int answer = INT_MAX;
};
/*
class Solution {
public:
    void binary(const vector<int> &nums, const int &p, int &left, int &right) {
        if (left > right) return;
        mid = (left + right) / 2;
        cnt = 0;
        taken = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (abs(nums[i] - taken) <= mid) {
                ++cnt;
                if ((i + 1) < nums.size())
                    taken = nums[i + 1];
                ++i;
            } else {
                taken = nums[i];
            }
        } 
        if (cnt < p) {
            left = mid + 1;
            binary(nums, p, left, right);
        } else {
            answer = min(answer, mid);
            right = mid - 1;
            binary(nums, p, left, right);
        }
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.back() - nums[0];
        binary(nums, p, left, right);
        return answer;
    }
private:
    int taken = 0;
    int cnt = 0;
    int mid = 0;
    int answer = INT_MAX;
};
*/

/*
class Solution {
public:
    void binary(const vector<int> &nums, const int &p, int &left, int &right) {
        if (left > right) return;
        mid = (left + right) / 2;
        cnt = 0;
        taken = -1;
        for (int i = 0; i != nums.size(); ++i) {
            if (taken == -1) {
                taken = nums[i];
            } else if (abs(nums[i] - taken) <= mid) {
                ++cnt;
                taken = -1;
            } else {
                taken = nums[i];
            }
        } 
        if (cnt < p) {
            left = mid + 1;
            binary(nums, p, left, right);
        } else {
            right = mid - 1;
            answer = min(answer, mid);
            binary(nums, p, left, right);
        }
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.back();
        binary(nums, p, left, right);
        return answer;
    }
private:
    int taken = 0;
    int cnt = 0;
    int mid = 0;
    int answer = INT_MAX;
};
*/

int main() {
  
  
  
  
  return 0;  
}

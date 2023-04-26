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

int main() {
  
  
  
  
  return 0;  
}

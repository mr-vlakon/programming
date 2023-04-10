class Solution {
public:
    void binary(const vector<int> &nums, const int &k, int &left, int &right) {
        if (left > right) return;
        mid = (left + right) / 2;
        taken = -1;
        cnt = 0;
        if (nums[0] <= mid) {
            taken = 0;
            cnt++;
        }
        for (int i = 1; i != nums.size(); ++i) {
            if (nums[i] <= mid &&  (i - taken) != 1) {
                ++cnt;
                taken = i;
            }
        }
        if (cnt >= k) {
            answer = min(mid, answer);
            right = mid - 1;
            binary(nums, k, left, right);
        } else {
            left = mid + 1;
            binary(nums, k, left, right);
        }
    }
    int minCapability(vector<int>& nums, int k) {
        int left = 1;
        int right = *max_element(nums.cbegin(), nums.cend());
        binary(nums, k, left, right);
        return answer;
    }
private:
    int mid = 0;
    int cnt = 0;
    int taken = 0;
    int answer = 1000000000;
};

int main() {

  
  
  return 0;  
}

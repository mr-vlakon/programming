class Solution {
public:
    void binary(const vector<int> &nums, const int &flip, int &left, int &right) {
        if (left > right) return;
        mid = (left + right) / 2;
        tmp = 100000;
        tmp = min(tmp, prefix[mid]);
        for (int i = 1; i <= nums.size() - mid + 1; ++i) {
            tmp = min(tmp, prefix[mid + i - 1] - prefix[i - 1]);
        }
        if (tmp <= flip) {
            answer = max(answer, mid);
            left = mid + 1;
            binary(nums, flip, left, right);
        } else {
            right = mid - 1;
            binary(nums, flip, left, right);
        }
    }
    int longestOnes(vector<int>& nums, int k) {
        int pref = 0;
        int cnt1 = 0;
        prefix.push_back(0);
        for (int i = 0; i != nums.size(); ++i) {
            if (nums[i] == 0) {
                pref++;
            } else {
                ++cnt1;
            }
            prefix.push_back(pref);
        }
        left = k;
        right = min(cnt1 + k, static_cast<int>(nums.size()));
        binary(nums, k, left, right);
        return answer;
    }
private:
    int tmp = 0;
    vector<int> prefix;
    int answer = 0;
    int left = 0;
    int right = 0;
    int mid = 0;
};

int main() {
  
  
  
  return 0;  
}

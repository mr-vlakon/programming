class Solution {
public:
    void binary(const vector<int> &nums, const int& maxOp, int &left, int &right) {
        if (left > right) return;
        mid = (left + right) / 2;
        cnt = 0;
        for (int i = 0; i != nums.size(); ++i) {
            if (nums[i] > (mid + 1)) {
                if ((nums[i] % (mid + 1)) == 0) {
                    cnt--;
                }
                cnt += nums[i] / (mid + 1);          
            }
        }
        if (cnt > maxOp) {
            left = mid + 1;
            binary(nums, maxOp, left, right);
        } else {
            answer = min(answer, (mid + 1));    
            right = mid - 1;
            binary(nums, maxOp, left, right);
        }
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 0;
        int right = *max_element(nums.cbegin(), nums.cend());
        binary(nums, maxOperations, left, right);
        return answer;
    }
private:
    int cnt = 0;
    int mid = 0;
    int answer = 1000000001;
};

int main() {
  
  
  return 0;  
}

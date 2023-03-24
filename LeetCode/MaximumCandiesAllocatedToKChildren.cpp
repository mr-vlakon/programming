class Solution {
public:
    void binary(const vector<int> &nums, int &left, int &right) {
        if (left > right) {
            return;
        }
        tmp = 0;
        mid = (left + right) / 2;
        for (int i = 0; i != nums.size(); ++i) {
            tmp += nums[i] / (mid + 1);
        }
        if (tmp >= K) {
            answer = max(answer, mid + 1);
            left = mid + 1;
            binary(nums, left, right); 
        } else {
            right = mid - 1;
            binary(nums, left, right);
        }
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = accumulate(candies.cbegin(), candies.cend(), 0LL);
        if (sum < k) return 0;
        K = k;
        int can = sum / k - 1;
        int left = 0;
        binary(candies, left, can);
        return answer;
    }
private:
    int K = 0;
    int mid = 0;
    long long tmp = 0;
    int answer = 0;
};

int main() {
  
  
  return 0;  
}

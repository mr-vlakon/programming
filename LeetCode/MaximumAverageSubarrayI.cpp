class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = accumulate(nums.cbegin(), nums.cbegin() + k, 0.0);
        double max = sum / k;
        for (int i = 1; i <= nums.size() - k; ++i) {
            sum -= nums[i - 1];
            sum += nums[i + k - 1];
            double av = sum / k;
            if (av > max)
                max = av;
        }
        return max;
    }
};

int main() {
  
  
  
  return 0;  
}

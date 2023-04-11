class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if (is_sorted(arr.rbegin(), arr.rend()))
            return 1;
        if (is_sorted(arr.begin(), arr.end())) {
            return arr.size();
        }
        vector<int> nums = arr;
        sort(arr.begin(), arr.end());
        int answer = 0;
        int maxV = 0;
        int j = 1;
        int start = 0;
        for (int i = 0; i < nums.size();) {
            while ((i < nums.size()) && nums[i] != start) {
                maxV = max(maxV, nums[i]);
                ++i;
            }
            maxV = max(maxV, start);
            j = maxV;
            start = maxV + 1;
            while (i < j) {
                while ((i < nums.size()) && i <= j) {
                    maxV = max(maxV, nums[i]);
                    if (i == j) break;
                    ++i;
                }
                j = maxV;
            }
            start = maxV + 1;
            ++i;
            ++answer;
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}

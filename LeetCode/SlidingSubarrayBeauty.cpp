class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        multiset<int> ms;
        //cout << *(next(ms.begin(), 2)) << endl;
        for (int i = 0; i != k; ++i) {
            if (nums[i] < 0) {
                ms.insert(nums[i]);
            }
        }
        vector<int> answer;
        if (ms.size() >= x) {
            answer.push_back(*next(ms.begin(), x - 1));
        } else {
            answer.push_back(0);
        }
        for (int i = 1; i < nums.size() - k + 1; ++i) {
            auto it = ms.find(nums[i - 1]);
            if (it != ms.cend())
                ms.erase(it);
            if (nums[i + k - 1] < 0) {
                ms.insert(nums[i + k - 1]);
            }
            if (ms.size() >= x) {
                answer.push_back(*next(ms.begin(), x - 1));
            } else {
                answer.push_back(0);
            }
        }       
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}

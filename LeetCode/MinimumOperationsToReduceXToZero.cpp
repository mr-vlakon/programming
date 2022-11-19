class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sum = accumulate(nums.cbegin(), nums.cend(), 0LL);
        sum -= x;
        deque<int> d;
        long long currSum = 0;
        int maxLength = -1;
        for (int i = 0; i != nums.size(); ++i) {
            d.push_back(nums[i]);
            currSum += nums[i];
            if (currSum == sum) {
                if (static_cast<int>(d.size()) > maxLength) {
                    maxLength = static_cast<int>(d.size());
                }
                if (static_cast<int>(d.size()) != 0) {
                    currSum -= d.front();
                    d.erase(d.begin());
                }        
            } else if (currSum > sum) {
                while (currSum > sum && static_cast<int>(d.size()) != 0) {
                    currSum -= d.front();
                    d.erase(d.begin());
                }
                if (currSum == sum && static_cast<int>(d.size()) > maxLength) {
                    maxLength = static_cast<int>(d.size());
                    if (static_cast<int>(d.size()) != 0) {
                        currSum -= d.front();
                        d.erase(d.begin());
                    }
                }
            }   
        }  
        return maxLength == -1 ? -1 : nums.size() - maxLength;
    }
};

int main() {
  
  
  return 0;  
}

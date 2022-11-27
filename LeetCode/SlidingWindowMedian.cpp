class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) return {nums.cbegin(), nums.cend()};
        vector<double> answer;
        multiset<long long> ms;
        for (int i = 0; i != k; ++i) {
            ms.insert(nums[i]);
            ++um[nums[i]];
        }
        
        if (k % 2 == 1) {
            auto it = next(ms.cbegin() , ms.size() / 2);
            answer.push_back(*it);
        } else {
            auto it1 = next(ms.cbegin(), ms.size() / 2 - 1);
            auto it2 = next(ms.cbegin(), ms.size() / 2);
            answer.push_back(static_cast<double>(*it1 + *it2) / 2.0);
        }
        
        for (int i = 1; i <= nums.size() - k; ++i) {
            um[nums[i - 1]]--;
            ms.erase(nums[i - 1]);
            if (um[nums[i - 1]] != 0) {
                auto tmp = um[nums[i - 1]];
                while (tmp != 0) {
                    ms.insert(nums[i - 1]);
                    --tmp;
                }
            }
            um[nums[i + k - 1]]++;
            ms.insert(nums[i + k - 1]);
            if (k % 2 == 1) {
                auto it = next(ms.cbegin(), ms.size() / 2);
                answer.push_back(*it);
            } else {
                auto it1 = next(ms.cbegin(), ms.size() / 2 - 1);
                auto it2 = next(ms.cbegin(), ms.size() / 2);
                answer.push_back(static_cast<double>(*it1 + *it2) / 2.0);
            }    
        }
        return answer;
    }
private:
    unordered_map<long long, int> um;
};

int main() {
  
  
  
  return 0;  
}

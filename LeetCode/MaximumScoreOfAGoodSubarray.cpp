class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int start = 0;
        int end = nums.size() - 1;
        int length = nums.size();
        int score = length * (*min_element(nums.cbegin(), nums.cend()));
        int answer = score;
        multiset<int> ms1;
        multiset<int> ms2;
        for (int i = 0; i <= k; ++i) {
            ms1.insert(nums[i]);
        }
        for (int i = k; i < nums.size(); ++i) {
            ms2.insert(nums[i]);
        }
        auto it1 = *ms1.begin();
        auto it2 = *ms2.begin();
        while ((start < end) && (start <= k) && (end >= k) )  {  
            if (it1 < it2) {
                auto it = ms1.find(nums[start]);
                ms1.erase(it);
                ++start;
            } else if (it1 >= it2) {
                auto it = ms2.find(nums[end]);
                ms2.erase(it);
                --end;
            }
            it1 = *ms1.begin();
            it2 = *ms2.begin();
            auto m = min(it1, it2);
            --length;
            score = m * length;
            if (score > answer) {
                answer = score;
            }          
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}

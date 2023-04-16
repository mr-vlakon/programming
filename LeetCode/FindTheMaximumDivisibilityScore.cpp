class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        vector<pair<int, int>> v;
        int cnt = 0;
        for (const auto &e: divisors) {
            cnt = 0;
            for (const auto &p: nums) {
                if ((p % e) == 0) {
                    ++cnt;
                }
            }
            v.push_back({cnt, e});
        }
        sort(v.begin(), v.end(), [](pair<int, int> &lhs, pair<int, int> &rhs) {
           return lhs.second < rhs.second; 
        });
        stable_sort(v.begin(), v.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
           return lhs.first > rhs.first; 
        });
        return v[0].second;        
    }
};

int main() {
  
  
  
  return 0;  
}

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto it = find_if(nums.cbegin(), nums.cend(), [=] (const int &x) {
           return x >= 0; 
        });
        vector<int> v(it, nums.cend());
        if (v.size() == 0) return 1;
        auto p = unique(v.begin(), v.end());
        v.erase(p, v.end());
        int x = 0;
        if (v[0] > 1)
            return 1;
        for (decltype(v.size()) i = 0; i != v.size() - 1; ++i) {
            if (v[i + 1] - v[i] != 1) {
                x = v[i] + 1;
                break;
            }
        }
        if (x == 0) {
            x = v[v.size() - 1] + 1;
        }
        return x;
    }
};

int main() {
  
  
  return 0;  
}

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<pair<int, size_t>> v;
        for (const auto& e: nums) {
            int res = 0;
            int q = e;
            while(q) {
                int tmp = q % 10;
                res += tmp;
                q /= 10;
            }
            v.push_back({e, res});
        }
        sort(v.begin(), v.end());
        stable_sort(v.begin(), v.end(), 
             [](const pair<int, size_t> &lhs, const pair<int, size_t> &rhs) {
                return lhs.second > rhs.second; 
             });
        int res = 0;
        int max = 0;
        for (decltype(v.size()) i = 0; i != v.size() - 1; ++i) {
            if (v[i].second == v[i + 1].second) {
                res = v[i].first + v[i + 1].first;
                if (res > max)
                    max = res;
            }
        }
        if (max != 0)
            return max;
        else
            return -1;
    }
};

int main() {

  
  return 0;  
}

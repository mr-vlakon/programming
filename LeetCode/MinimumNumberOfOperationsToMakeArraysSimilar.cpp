class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        
        vector<int> chetnoe;
        vector<int> nechetnoe;
        
        vector<pair<int,int>> v;
        
        for (const auto &e: nums) {
            if (e % 2 == 0) {
                chetnoe.push_back(e);
            } else {
                nechetnoe.push_back(e);
            }
        }
        
        int indx_ch = 0;
        int indx_nc = 0;
        for (const auto &e: target) {
            if (e % 2 == 0) {
                v.push_back({e, chetnoe[indx_ch]});
                ++indx_ch;
            } else {
                v.push_back({e, nechetnoe[indx_nc]});
                ++indx_nc;
            }
        }
        
        long long total = 0;
        for (const auto &e: v) {
            long long tmp = abs(e.first - e.second);
            total += tmp / 2;
            
        }
        
        return total / 2;
        
    }
};

int main() {

  
  
  return 0;  
}

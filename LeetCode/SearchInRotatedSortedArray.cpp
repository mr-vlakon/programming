class Solution {
public:
    int search(vector<int>& nums, int target) {
        map<int,size_t> mp;
        auto index = 0;
        for (const auto &e: nums) {
            mp[e] = index++;
        }
        
        if (mp.find(target) == mp.cend()) {
            return -1;
        } else
            return mp[target];
    }
};

int main() {
  
 return 0; 
}

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        map<int,size_t> mp;
        auto index = 0;
        for (const auto &e: nums) {
            mp[e] = index++;
        }
        
        if (mp.find(target) == mp.cend()) {
            return false;
        } else
            return true;    
    }
};

int main() {
  
  return 0; 
}

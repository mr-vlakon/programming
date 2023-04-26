class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for (const auto &e: nums) {
            um[e]++;
        }
        int ans = 0;
        unordered_map<int, int>::iterator it;
        for (const auto &e: um) {
            it = um.find(e.first + k);
            if (it != um.cend() && it->second > (1 - k)) {
                ++ans;
            }
        }
        return ans;
    }
};
/*
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for (const auto &e: nums) {
            um[e]++;
        }
        int ans = 0;
        unordered_map<int, int>::iterator it;
        for (const auto &e: um) {
            it = um.find(e.first + k);
            if (it != um.cend() && ((k != 0 && it->first != e.first) || (k == 0 && it->second > 1))) {
                ++ans;
            } 
        }
        return ans;
    }
};
*/
/*
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for (const auto &e: nums) {
            um[e]++;
        }
        int ans = 0;
        unordered_map<int, int>::iterator it;
        for (const auto &e: um) {
            it = um.find(e.first + k);
            if (it != um.cend() && it->first != e.first) {
                ++ans;
            } else if (it != um.cend() && it->second > 1) {
                ++ans;
            }
        }
        return ans;
    }
};
*/

int main() {
  
  
  
  return 0;  
}

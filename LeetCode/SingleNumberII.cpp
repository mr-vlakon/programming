class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, size_t> um1;
        for (const auto &e: nums) {
            ++um1[e];
        }
        for (const auto &e: um1) {
            if (e.second == 1) {
                return e.first;
            }
        }
        
        return 0;
    }
};

int main() {

  return 0;  
}

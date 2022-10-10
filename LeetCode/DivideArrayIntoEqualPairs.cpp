class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, size_t> um;
        for (const auto &e: nums)
            ++um[e];
        for (const auto &e: um) {
            if (e.second % 2 != 0)
                return false;
        }
        return true;
    }
};

int main() {
  
  
  return 0;  
}

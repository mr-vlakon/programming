class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        unordered_map<int, int> um;
        for (const auto &e: nums) {
            um[e] = abs(e);
        }
        
        int min = 10000000;
        vector<int> v;
        for (const auto &e: um) {
            if (e.second < min) {
                min = e.second;
            }
        }
        for (const auto &e: um) {
            if (min == e.second)
                v.push_back(e.first);
        }
        
        return *max_element(v.cbegin(), v.cend());
    }
};

int main() {
  
  

  return 0;
}

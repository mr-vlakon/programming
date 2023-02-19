class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int, int> um;
        for (const auto &e: nums1) {
            um[e[0]] += e[1]; 
        }
        for (const auto &e: nums2) {
            um[e[0]] += e[1]; 
        }
        vector<vector<int>> v;
        for (const auto &e: um) {
            v.push_back({e.first, e.second});
        }
        sort(v.begin(), v.end(), [] (vector<int> &lhs, vector<int> &rhs) {
            return lhs[0] < rhs[0];
        });
        return v;
    }
};

int main() {
  
  
  
  return 0;  
}

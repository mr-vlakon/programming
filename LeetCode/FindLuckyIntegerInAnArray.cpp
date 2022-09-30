class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, size_t> um;
        for (const auto &e: arr)
            ++um[e];
        vector<int> v;
        for (const auto &e: um) {
            if (e.first == e.second) {
                v.push_back(e.first);
            }
        }
        if (v.size() == 0)
            return -1;
        else
            return *max_element(v.cbegin(), v.cend());
    }
};

int main() {
  
  
  return 0;  
}

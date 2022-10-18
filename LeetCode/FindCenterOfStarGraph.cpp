class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, size_t> m;
        for (const auto &e: edges) {
            for (const auto &p : e) {
                ++m[p];
            }
        }   
        int max = 0;
        int value = 0;
        for (const auto &e: m) {
            if (e.second > max) {
                max = e.second;
                value = e.first;
            }
        }
        return value;
    }
    
};

int main() {
  
  
  return 0;  
}

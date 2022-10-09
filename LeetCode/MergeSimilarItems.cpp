class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        unordered_map<int, int> um;
        for (const auto &e: items1) {
            um[e[0]] += e[1];
        }
        for (const auto &e: items2) {
            um[e[0]] += e[1];
        }
        vector<vector<int>> v;
        for (const auto &e: um) {
            v.push_back({e.first, e.second});
        }
        
        sort(v.begin(), v.end(), [=](const vector<int> &lhs, const vector<int> &rhs) {
           return lhs[0] < rhs[0]; 
        });
        
        return v;
    }
};

int main() {
  
  
  return 0;  
}

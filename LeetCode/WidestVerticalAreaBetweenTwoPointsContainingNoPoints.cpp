class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> v;
        for (const auto &e: points) {
            v.push_back(e[0]);
        }
        sort(v.begin(), v.end());
        auto p = unique(v.begin(), v.end());
        v.erase(p, v.end());
        int max = 0;
        for (decltype(v.size()) i = 1; i != v.size(); ++i) {
            if (v[i] - v[i - 1] > max)
                max = v[i] - v[i - 1];
        }
        
        return max;
        
    }
};

int main() {
  
  
  return 0;  
}

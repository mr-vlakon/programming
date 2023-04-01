class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int prev = 0;
        int maxV = 0;
        unordered_map<char, int> um;
        for (int i = 0; i != 26; ++i) {
            um['a' + i] = i + 1;
        }
        for (int i = 0; i != chars.size(); ++i) {
            um[chars[i]] = vals[i];
        }
        for (const auto &e: s) {
            prev += um[e];
            maxV = max(prev, maxV);
            if (prev < 0) {
                prev = 0;
            }
        }
        return maxV;
    }
};

int main() {
  
  
  
  return 0;  
}

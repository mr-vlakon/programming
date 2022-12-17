class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> um;
        for (int i = 0; i != s.size(); ++i) {
            um[s[i]] = i;
        }
        vector<int> result;
        for (int j = 0; j != s.size(); ++j) {
            int tmp = um[s[j]];
            for (int q = j + 1; q < tmp; ++q) {
                if (um[s[q]] > tmp) {
                    tmp = um[s[q]];
                }
            }
            result.push_back(tmp - j + 1);
            j = tmp;
        }
        return result;
    }
};

int main() {
  
  
  
  return 0;  
}

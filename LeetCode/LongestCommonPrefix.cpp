class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prev = strs[0];
        for(decltype(strs.size()) i = 1; i != strs.size(); ++i) {
                string curr;
                for (decltype(prev.size()) k = 0; k != min(prev.size(), strs[i].size()); ++k){
                    if(prev[k] == strs[i][k]) {
                        curr += strs[i][k];
                    } else
                        break;                    
                }
                prev = curr;
        }
        return prev;
    }
};

int main() {
  
  
  return 0;  
}

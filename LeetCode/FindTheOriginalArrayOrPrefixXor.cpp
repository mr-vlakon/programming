class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans{pref[0]};
        for (decltype(pref.size()) i = 1; i != pref.size(); ++i) {
            ans.push_back(pref[i]^pref[i - 1]);
        }
        return ans;   
    }
};

int main() {
  
  
  return 0;  
}

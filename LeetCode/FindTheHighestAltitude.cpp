class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int min = 10000;
        int val = 0;
        vector<int> ans{0};
        int prev = 0;
        for (decltype(gain.size()) i = 0; i != gain.size(); ++i) {
            ans.push_back(gain[i] + prev);
            prev = ans.back();
        }
        return *max_element(ans.cbegin(), ans.cend());
    }
};

int main() {
  
  
  return 0;  
}

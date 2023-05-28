class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> firstOccurence(26, -1);
        vector<int> secondOccurence(26, -1);
        for (int i = 0; i != s.size(); ++i) {
            if (firstOccurence[s[i] - 'a'] == -1) {
                firstOccurence[s[i] - 'a'] = i;
            }
            secondOccurence[s[i] - 'a'] = i;
        }
        unordered_map<int, int> um;
        int ans = 0;
        for (int j = 0; j != firstOccurence.size(); ++j) {
            if (firstOccurence[j] != -1 && abs(firstOccurence[j] - secondOccurence[j]) >= 2) {
                 ++firstOccurence[j];
                 --secondOccurence[j];
                while (firstOccurence[j] <= secondOccurence[j]) {
                    ++um[s[firstOccurence[j]]];
                    ++firstOccurence[j];
                }
                ans += um.size();
                um.clear();
            }
        }
        return ans;
    }
};

int main() {
  
  
  
  return 0;  
}

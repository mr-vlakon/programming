class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<int> dp(words.size(), n);
        vector<vector<string>> v(n);
        dp[0] = 1;
        for (int i = 0; i != n; ++i) {
            int tmpMax = 0;
            vector<string> tmp;
            for (int j = 0; j < i; ++j) {
                if (groups[i] == 1) {
                    if (groups[j] == 0) {
                        if (dp[j] > tmpMax) {
                            tmpMax = dp[j];
                            tmp = v[j];
                        }
                    }
                } else {
                    if (groups[j] == 1) {
                        if (dp[j] > tmpMax) {
                            tmpMax = dp[j];
                            tmp = v[j];
                        }
                    }
                    
                }
            }
                dp[i] = tmpMax + 1;
                v[i] = tmp;
                v[i].push_back(words[i]);
        }
        
        return v.back();
    }
};

int main()
{


  return 0;
}

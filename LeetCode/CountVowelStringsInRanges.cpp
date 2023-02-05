class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix{0};
        int cnt = 0;
        for (int i = 0; i != words.size(); ++i) {
            if (((words[i][0] == 'a' || words[i][0] == 'e' ||  words[i][0] == 'i' ||  words[i][0] == 'o' ||  words[i][0] == 'u')) && 
                (words[i].back() == 'a' || words[i].back() == 'e' ||  words[i].back() == 'i' ||  words[i].back() == 'o' ||  words[i].back() == 'u')) {
                ++cnt;
            }
            prefix.push_back(cnt);
        }
        vector<int> result;
        for (const auto &e: queries) {
            result.push_back(prefix[e[1] + 1] - prefix[e[0]]);
        }
        return result;
    }
};

int main() {
  
  
  return 0;  
}

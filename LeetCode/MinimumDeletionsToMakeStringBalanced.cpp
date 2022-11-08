class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> prefix;
        vector<int> suffix;
        int cntb = 0;
        int cnta = 0;
        for (int i = 0, j = s.size() - 1; i != s.size() && j >= 0; ++i, --j) {
            prefix.push_back(cntb);
            suffix.push_back(cnta);
            if (s[i] == 'b')
                ++cntb;
            if (s[j] == 'a')
                ++cnta;
        }
        reverse(suffix.begin(), suffix.end());
        int min = 10000000;
        for (decltype(s.size()) i = 0; i != s.size(); ++i) {
            int tmp = prefix[i] + suffix[i];
            if (tmp < min)
                min = tmp;
        }
        return min;        
    }
};

int main() {
  
  
  
  return 0;  
}

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int numberOfRows = 1;
        int cnt = 0;
        for (int i = 0; i != s.size(); ++i) {
            cnt += widths[s[i] - 'a'];
            if (cnt > 100) {
                ++numberOfRows;
                cnt = widths[s[i] - 'a'];
            }
        }        
        return {numberOfRows, cnt};
    }
};

int main() {
  
  
  
  return 0;  
}

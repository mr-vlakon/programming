class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<string> v(numRows);
        int j = 0;
        bool direction = true;
        for (int i = 0; i != s.size(); ++i) {
            if (direction) {
                v[j].push_back(s[i]);
                ++j;
                if (j == (numRows - 1)) {
                    direction = false;
                }
            } else if (!direction) { 
                v[j].push_back(s[i]);
                --j;   
                if (j == 0) {
                    direction = true;
                }
            }
        }
        string result;
        for (const auto &e: v) {
            result += e;
        }
        return result;
    }
};

int main() {
  
  
  
  return 0;  
}

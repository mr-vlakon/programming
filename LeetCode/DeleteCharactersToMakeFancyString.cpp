class Solution {
public:
    string makeFancyString(string s) {
        string res;
        auto prev = 0;
        int i = 0;
        while (i != s.size()) {
            res.push_back(s[i]);
            auto pos = s.find_first_not_of(s[i], prev);
            if (pos == string::npos)  {
                if (s.size() - prev >= 2) {
                    res.push_back(s[i]);
                }
                break;
            }
            if (pos - prev >= 2) {
                res.push_back(s[i]);
            }
            prev = pos;
            i = pos;
        }
        return res;
    }
};

int main() {
  
  
  
  
  return 0;  
}

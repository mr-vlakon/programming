class Solution {
public:
    string reformat(string s) {
        vector<char> digits;
        vector<char> chars;
        for (const auto &e: s) {
            if(isdigit(e))
                digits.push_back(e);
            else
                chars.push_back(e);
        }
        if (abs(static_cast<int>(digits.size()) - static_cast<int>(chars.size())) > 1) return "";
        string result;
        int k = 0, l = 0;
        int start = 0;
        if (digits.size() >= chars.size())
            start = 1;
        for (decltype(s.size()) i = 0; i != s.size(); ++i) {
            if (start == 1) {
                if(i % 2 == 0)
                    result += digits[k++];
                else
                    result += chars[l++];
            } else {
                if(i % 2 == 1)
                    result += digits[k++];
                else
                    result += chars[l++];
                
            }
        }
        return result;
    }
};

int main() {
  
  return 0;  
}

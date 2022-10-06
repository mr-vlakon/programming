class Solution {
public:
    string discountPrices(string sentence, int discount) {
        istringstream is(sentence);
        string s;
        string result;
        while(is >> s) {
            if (s[0] == '$' && s.size() > 1) {
                string tmp(s.begin() + 1, s.end());
                auto ppos = tmp.find_first_not_of("0123456789");
                if (ppos == string::npos) {
                    long double x = stod(tmp);
                    long double y = 0.0;
                    long double k = (100.00 - static_cast<double>(discount)) / 100.00;
                    y = k * x;
                    string yy = to_string(y);
                    auto pos = yy.find('.');
                    if (yy[pos + 3] - '0' >= 5) {
                        ++yy[pos + 2];
                    }
                    string tmpRes = string(yy.cbegin(), yy.cbegin() + pos + 3);
                    s.replace(1, tmp.size(), tmpRes);
                }
            }
            result += s + " ";
        }
        result.erase(--result.cend());
        
        return result;
    }
};

int main() {
  
  return 0;  
}

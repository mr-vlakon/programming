class Solution {
public:
    string fractionAddition(string expression) {
        string tmp;
        unordered_set<int> v;
        string numerStr;
        string denomStr;
        size_t pos = 0;
        int endStr = 0;
        for (int i = 0; i < expression.size(); ++i) {
            if (expression[i] == '/') {
                pos = expression.find_first_of("+-", i + 1);
                endStr = (pos == string::npos) ? expression.size() : pos;
                v.insert(stoi(string(expression.cbegin() + i + 1, expression.cbegin() + endStr)));
                i = endStr;
            }
        }
        pos = 0;
        int numerator = 0;
        int numeratorTmp = 0;
        int denominatorTmp = 0;
        size_t pos1 = 0;
        while (pos != string::npos) {
            pos1 = expression.find_first_of("/", pos);
            numerStr = string(expression.cbegin() + pos, expression.cbegin() + pos1);
            pos = pos1 + 1;
            pos1 = expression.find_first_of("+-", pos);    
            endStr = (pos1 == string::npos) ? expression.size() : pos1;
            denomStr = string(expression.cbegin() + pos, expression.cbegin() + endStr);
            numeratorTmp = stoi(numerStr);
            denominatorTmp = stoi(denomStr);
            for (const auto &e: v) {
                if (denominatorTmp != e) {
                    numeratorTmp *= e;
                }
            }
            numerator += numeratorTmp;
            pos = pos1;
        }
        if (numerator == 0) return "0/1";
        int denominator = 1;
        for (const auto &e:v) {
            denominator *= e;
        }
        int gcd_ = gcd(abs(numerator), abs(denominator));
        numerator /= gcd_;
        denominator /= gcd_;
        string result;
        result += to_string(numerator) + "/" + to_string(denominator);
        return result;
    }
};

int main() {
  
  
  
  
  
  
  return 0;  
}

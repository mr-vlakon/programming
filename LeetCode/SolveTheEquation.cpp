class Solution {
public:
    string solveEquation(string equation) {
        size_t pos = 0;
        size_t prev = 0;
        int status = 1;
        int endStr = 0;
        int coef = 0;
        int cf = 0;
        string str;
        while (pos != string::npos) {
            if (equation[pos] == '=') {
                status = -1;
                ++pos;
            }
            prev = pos;
            pos = equation.find_first_of("+-x=", pos + 1);
            endStr = (pos != string::npos) ? (pos) : equation.size();
            str = string(equation.cbegin() + prev, equation.cbegin() + endStr); 
            if (str == "x") {
                coef += status*1;
            }
            if (pos == string::npos)   {
                if (str.size() == 0) break;
                if (str == "x" || str == "-" || str == "+") {
                    if (str == "-") {
                        coef -= status*1;
                    } else if (str == "+") {
                        coef += status*1;
                    }
                } else {
                    cf += status*stoi(str);
                }
                break;
            }
            if (equation[pos] == 'x' && str != "+" && str != "-" && str != "x") {
                coef += status*stoi(str);
            } else if (str != "+" && str != "-" && str != "x"){
                cf += status*stoi(str);
            } else {
                if (str == "+") {
                    ++pos;
                    coef += status*1;
                } else if (str == "-") {
                    ++pos;
                    coef -= status*1;
                }
            }
            if (pos != string::npos && equation[pos] == 'x') ++pos;
        }
        cf = -cf;
        if (coef == 0 && cf == 0) return "Infinite solutions";
        if (cf == 0) return "x=0";
        if (coef == 0) return "No solution";        
        int x = gcd(cf, coef);
        cf /= x;
        coef /= x;      
        if (cf < 0 && coef < 0) {
            cf = -cf;
            coef -coef;
        } else if (cf < 0 || coef < 0) {
            cf = -abs(cf);
            coef = abs(coef);
        }
        string answer;
        if (abs(coef) == 1) {
            answer = "x=" + to_string(cf);
        } else {
            answer = "x=" + to_string(cf) + "/" + to_string(coef);
        }
        return answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}

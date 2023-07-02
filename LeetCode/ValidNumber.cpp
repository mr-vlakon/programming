class Solution {
public:
    bool isNumber(string s) {
        int countDot = 0;
        int countE = 0;
        for (const auto &e: s) {
            if (e == '.') {
                ++countDot;
            } else if (e == 'e' || e == 'E') {
                ++countE;
            } else if (!isdigit(e) && e != '-' && e != '+') {
                return false;
            }
        }
        if (countDot > 1) return false;
        if (countE > 1) return false;
        if (s.back() == 'e' || s.back() == 'E' || s.back() == '+' || s.back() == '-') 
            return false;
        bool flagS = false;
        bool flagE = false;
        char prev;
        for (int i = 0; i != s.size(); ++i) {
            if (s[i] == '.') {
                if (flagE) return false;
                if (!isdigit(prev)) {
                    if ((i + 1) >= s.size()) return false;
                    if (!isdigit(s[i + 1])) return false;
                }
            }
            if (s[i] == '-' || s[i] == '+') {
                if (flagS) return false;
            } else if (s[i] == 'e' || s[i] == 'E'){
                if (flagE) return false;
                if (!isdigit(prev) && prev != '.' && (prev != '+' || prev != '-')) {
                    return false;
                }
                flagS = false;
                flagE = true;
            } else if (prev == '.' && !isdigit(s[i])) {
                return false;
            } else 
                flagS = true;
            prev = s[i];
        }
        return true;
    }
};
/*
class Solution {
public:
    bool isNumber(string s) {
        int countDot = 0;
        int countE = 0;
        for (const auto &e: s) {
            if (e == '.') {
                ++countDot;
            } else if (e == 'e' || e == 'E') {
                ++countE;
            } else if (!isdigit(e) && e != '-' && e != '+') {
                return false;
            }
        }
        if (countDot > 1) return false;
        if (countE > 1) return false;
        if (s.back() == 'e' || s.back() == 'E' || s.back() == '+' || s.back() == '-') 
            return false;
        bool flagS = false;
        bool flagE = false;
        char prev;
        for (int i = 0; i != s.size(); ++i) {
            if (s[i] == '.') {
                if (flagE) return false;
                if (!isdigit(prev)) {
                    if ((i + 1) >= s.size()) return false;
                    if (!isdigit(s[i + 1])) return false;
                }
            }
            if ((s[i] == '-' || s[i] == '+') && !flagS) {
                flagS = true;
            } else if (isdigit(s[i]) || s[i] == '.') {
                flagS = true;
            } else if ((s[i] == '-' || s[i] == '+') && flagS == true) {
                return false;
            } else if ((s[i] == 'e' || s[i] == 'E') && flagE == false){
                if (!isdigit(prev) && prev != '.') return false;
                flagS = false;
                flagE = true;
            } else if ((s[i] == 'e' || s[i] == 'E')) {
                return false;
            } else if (prev == '.' && !isdigit(s[i])) {
                return false;
            }
            prev = s[i];
        }
        return true;
    }
};
*/
int main() {

  
  return 0;
}

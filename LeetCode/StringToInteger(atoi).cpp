class Solution {
public:
    int myAtoi(string s) {
        int start = 0;
        int st = -1;
        long long tmp = 0;
        bool findSpace = false;
        bool findS = false;
        bool findFirstNotNull = false;
        bool findD = false;
        bool signC = true;
        while (start < s.size()) {
            if (s[start] == ' ' || isdigit(s[start]) || s[start] == '-' || s[start] == '+') {
                    if (s[start] == ' ' && findSpace == true) break;
                    if (s[start] == '+' || s[start] == '-' ) {
                        if (findS == true) break;
                        if (!findS)
                            signC = (s[start] == '-') ? false : true;
                        findS = true;
                    } 
                    if (s[start] == ' ' && (findSpace == true && findD == true)) break;
                    if (isdigit(s[start]) || s[start] == '+' || s[start] == '-') findSpace = true;
                    if (isdigit(s[start])) {
                        findS = true;
                        if (s[start] != ' ' && s[start] != '0' && findFirstNotNull == false) {
                            findD = true;
                            st = start;
                            findFirstNotNull = true;
                        }
                    }
            } else {
                break;
            }
            ++start;
        }
        if (st == -1) st = start;
        for (int i = st; i < start; ++i) {
            if (s[i] == ' ' || isdigit(s[i]) || s[i] == '-' || s[i] == '+') {
                if ((start - i - 1) > 9) {
                    return signC == true ? INT_MAX : INT_MIN;
                } else if ((start - i - 1) == 9) {
                    if ((s[i] - '0') > 2) {
                        return signC == true ? INT_MAX : INT_MIN;
                    }
                    tmp += (s[i] - '0')*pow(10, start - i - 1);
                } else {
                    tmp += pow(10, start - i - 1)*(s[i] - '0');
                }
            }
        }
        if (signC == true && tmp >= INT_MAX) {
            return INT_MAX;
        } else if (signC == true) {
            return tmp;
        } else if (signC == false && tmp >= (INT_MAX + 1LL)) {
            return INT_MIN;
        } else if (signC == false) {
            return -tmp;
        }
        return 0;
    }
};

int main() {

  
  return 0;
}

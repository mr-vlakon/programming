class Solution {
public:
    int countValidWords(string sentence) {
        int cnt = 0;
        istringstream is(sentence);
        string s;
        bool status = true;
        int cntHyphen = 0;
        while (is >> s) {
            status = true;
            cntHyphen = 0;
            for (int i = 0; i != s.size(); ++i) {
                if (ispunct(s[i]) && s[i] != '-' && i != (s.size() - 1)) {
                    status = false;
                    break;
                } else if (s[i] == '-') {
                    if (cntHyphen == 1) {
                        status = false;
                        break;
                    }
                    cntHyphen++;
                    if ((i - 1) < 0) {
                        status = false;
                        break;
                    }
                    if ( (i + 1) >= s.size()) {
                        status = false;
                        break;
                    }
                    if (!isalpha(s[i - 1])) {
                        status = false;
                        break;
                    }
                    if (!isalpha(s[i + 1])) {
                        status = false;
                        break;
                    }
                    if (!islower(s[i - 1])) {
                        status = false;
                        break;
                    }
                    if (!islower(s[i + 1])) {
                        status = false;
                        break;
                    }
                } else if (isdigit(s[i])) {
                    status = false;
                    break;
                }
            }
            if (status) {
                ++cnt;
            }
        }
        return cnt;
    }
};

int main() {
  
  
  return 0;  
}

class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string rem = s;
        char remD;
        bool status = false;;
        for (int i = 0; i != s.size(); ++i) {
            if (s[i] != '9' && !status) {
                status = true;
                remD = s[i];
                s[i] = '9';
            } else if (status) {
                if (s[i] == remD) {
                    s[i] = '9';
                }
            }
        }
        status = false;
        for (int i = 0; i != rem.size(); ++i) {
            if (!status) {
                status = true;
                remD = rem[i];
                rem[i] = '0';
            } else if (status) {
                if (rem[i] == remD) {
                    rem[i] = '0';
                }
            }
        }
        return stoi(s) - stoi(rem);       
    }
};

int main() {
  
  
  return 0;  
}

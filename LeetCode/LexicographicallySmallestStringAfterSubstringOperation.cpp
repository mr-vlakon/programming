class Solution {
public:
    string smallestString(string s) {
        bool status = false;
        int pos = 0;
        for (int i = 0; i != s.size(); ++i) {
            if ((s[i] - 'a') != 0) {
                status = true;
                --s[i];
            } else if (status) {
                break;
            } else if ((s[i] - 'a') == 0) {
                pos = i;
            }
        }
        if (!status) s[pos] = 'z';
        return s;
    }
};
/*
class Solution {
public:
    string smallestString(string s) {
        bool status = false;
        for (auto &e: s) {
            if ((e - 'a') != 0) {
                status = true;
                --e;
            } else if (status) {
                break;
            }
        }
        if (!status) {
            for (int i = s.size() - 1; i >= 0; --i) {
                if ((s[i] - 'a') == 0) {
                    s[i] = 'z';
                    break;
                }
            }
        }
        return s;
    }
};
*/
int main() {
  
  
  return 0;  
}

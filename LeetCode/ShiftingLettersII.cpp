class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> v(s.size(), 0);
        for (const auto &e: shifts) {
            v[e[1]] += (e[2] == 0) ? -1 : 1;
            if ((e[0] - 1) >= 0) {
                v[e[0] - 1] += (e[2] == 0) ? 1 : -1;
            }
        }
        int pref = 0;
        for (int i = v.size() - 1; i >= 0; --i) {
            pref += v[i];
            if (pref > 0) {
                s[i] = ((pref + s[i] - 'a') % 26) + 'a';
            } else {
                s[i] = s[i] + (pref % 26);
                if (s[i] < 'a') {
                    s[i] += 26 ;
                }
            }
        }
        return s;
    }
};
/*
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> v(s.size(), 0);
        for (const auto &e: shifts) {
            v[e[1]] += (e[2] == 0) ? -1 : 1;
            if ((e[0] - 1) >= 0) {
                v[e[0] - 1] += (e[2] == 0) ? 1 : -1;
            }
        }
        int pref = 0;
        int t = 0;
        int tmp = 0;
        for (int i = v.size() - 1; i >= 0; --i) {
            pref += v[i];
            if (pref > 0) {
                s[i] = ((pref + s[i] - 'a') % 26) + 'a';
            } else {
                t = -(pref % 26);
                tmp = max(0, s[i] - 'a' - t);
                t -= (s[i] - 'a' - tmp);
                s[i] = tmp + 'a';
                if (t > 0) {
                    --t;
                    s[i] = 'z';
                }
                if (t > 0) {
                    s[i] -= t;
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

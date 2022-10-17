class Solution {
public:
    string countAndSay(int n) {
        vector<string> cntNSay(n + 1);
        if (n + 1 == 1) return "0";
        cntNSay[0] = "1";
        if (n + 1 == 1) return "1";
        cntNSay[1] = "11";
        int i = 2;
        while (i < n) {
            int cnt = 1;
            string res;
            for (decltype(cntNSay[i - 1].size()) k = 1; k <= cntNSay[i - 1].size(); ++k) {
                if (k == cntNSay[i - 1].size()) {
                    res += to_string(cnt) + cntNSay[i - 1].back();
                    break;
                }
                if (cntNSay[i - 1][k] != cntNSay[i - 1][k - 1]) {
                    res += to_string(cnt) + cntNSay[i - 1][k - 1];
                    cnt = 1;
                } else {
                    ++cnt;
                }
            }
            cntNSay[i] = res;
            ++i;
        }
        return cntNSay[n - 1];
    }
};

int main() {

  
  
  return 0;  
}

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> pw;
        int x = n;
        bool status = false;
        while (x != 1) {
            int tmp = x % 2;
            if (tmp == 1) {
                status = true;
                break;
            }    
            x /= 2;
        }
        
        double i = 0;
        int sum = 0;
        bool finish = false;
        
        if (status == true) {
            while (sum < n) {
                double tmp = pow(2.0, i);
                pw.push_back(static_cast<int>(tmp));
                sum += tmp;
                i += 1.0;
            }
        } else {
            pw.push_back(n);
            finish = true;
        }
        vector<int> pww;
        if (finish == false) {
            reverse(pw.begin(), pw.end());
            if (status == true) {
                for (decltype(pw.size()) i = 0; i != pw.size(); ++i) {
                    if (n - pw[i] >= 0) {
                        pww.push_back(pw[i]);
                        n -= pw[i];
                    } 
                    if (n == 0)
                        break;
                }
            }
        } else {
            pww.push_back(n);
        }
        sort(pww.begin(), pww.end());
        vector<int> ans;
        for (auto &e: queries) {
            long long tmp = 1;
            while (e[0] <= e[1]) {
                tmp *= pww[e[0]];
                tmp %= 1000000007; 
                ++e[0];
            }
            tmp %= 1000000007;
            ans.push_back(tmp);
        }
        return ans;
    }
};

int main() {
  
  
  return 0;  
}

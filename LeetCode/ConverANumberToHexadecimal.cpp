class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        bool status = false;
        long long nm = num;
        if (num < 0) {
            status = true;
            if (num == -2147483648)
                nm = 2147483648;
            else
                nm = -num;
        }
        vector<int> q(32);
        int index = 0;
        while(nm) {
            int tmp = nm % 2;
            q[index++] = tmp;
            nm /= 2;
        }
        reverse(q.begin(), q.end());
        if (status) {
            for (auto &e: q) {
                if (e == 0)
                    e = 1;
                else
                    e = 0;
            }
            int perenos = 0;
            reverse(q.begin(), q.end());
            for (decltype(q.size()) i = 0; i != q.size(); ++i) {
                if (i == 0) {
                    ++q[i]; 
                } else {
                    q[i] += perenos;
                }
                if (q[i] >= 2) {
                    q[i] = 0;
                    perenos = 1;
                } else
                    perenos = 0;
            }
            reverse(q.begin(), q.end());
        }
        string res;
        for (decltype(q.size()) i = 0; i != 8; ++i) {
            string tmp;
            tmp = to_string(q[4 * i]) + to_string(q[4 * i + 1]) 
                + to_string(q[4 * i + 2]) + to_string(q[4 * i + 3]);
            int r =
                8 * q[4 * i] + 4 * q[4 * i + 1] + 2 * q[4 * i + 2] + 1 * q[4 * i + 3];
            if (r >= 10) {
                if (tmp == "1010")
                    res += 'a';
                if (tmp == "1011")
                    res += 'b';
                if (tmp == "1100")
                    res += 'c';
                if (tmp == "1101")
                    res += 'd';
                if (tmp == "1110")
                    res += 'e';
                if (tmp == "1111")
                    res += 'f';
            } else
                res += to_string(r);
        }        
        auto pos = res.find_first_not_of("0");
        string str(res.cbegin() + pos, res.cend());        
        return str;
    }
};

int main() {

  
  return 0;  
}

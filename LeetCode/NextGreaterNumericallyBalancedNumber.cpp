class Solution {
public:
    int nextBeautifulNumber(int n) {
        int x = n + 1;
        int res = x;
        vector<int> result;
        while(true) {
            result.resize(0);
            while(res) {
                int tmp = res % 10;
                result.push_back(tmp);
                res /= 10;
            }
            bool status = true;
            for (const auto &e: result) {
                if (count(result.cbegin(), result.cend(), e) != e) {
                    status = false;
                    break;
                }
            }
            if (status) {
                int cnt = 1;
                for (const auto &e: result) {
                    res += cnt * e;
                    cnt *= 10;
                }
                return res;
            }
            res = ++x;
        }
        return 0;
    }
};

int main() {
  
  return 0;  
}

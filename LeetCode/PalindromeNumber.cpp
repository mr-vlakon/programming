class Solution {
public:
    bool isPalindrome(int x) {
        int tmp = 0;
        int t = x;
        string s = to_string(x);
        if (s[0] == '-') {
            return false;
        }
        vector<unsigned> v;
        bool status = false;
        while (x) {
            tmp = (x % 10);
            if (tmp == 0 && status == false) {
            } else {
                v.push_back(tmp);
            }
            status = true;
            x /= 10;
        }
        unsigned result = 0, cnt = 1;
        int size = v.size() - 1;
        while (size >= 0) {
            result += cnt * v[size];
            cnt *= 10;
            --size;
        }
        if (result == t) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {

  
  return 0;  
}

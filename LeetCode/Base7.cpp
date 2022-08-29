class Solution {
public:
    string convertToBase7(int num) {
        int x = num;
        string s;
        bool status = false;
        if (x < 0) {
            x = -x;
            status = true;
        }
        if (x == 0) return "0";
        int tmp = 0;
        while (x) {
            tmp = x % 7;
            s += to_string(tmp);
            x /= 7;
        }
        if (status)
            s += "-";
        reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
  
  return 0;  
}

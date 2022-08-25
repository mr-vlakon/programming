class Solution {
public:
    int reverse(int x) {
        int tmp = 0;
        int y = x;
        int i = 0;
        int state = 0;
        string s = to_string(x);
        vector<unsigned> v;
        while(y){
            tmp = abs(y % 10);
            if (tmp == 0 && state == 0){
            } else {
                v.push_back(tmp);
            }
            state = 1;
            y /=10;
        }
        int new_result = 0;
        int k = 0;
        unsigned long long cnt = 1;
        unsigned long long ui = 0;
        while(k != v.size()) {
            ui += (unsigned long long)v[v.size() - k - 1] * cnt;
            cnt *= 10;
            ++k;
        }
        if (s[0] == '-') {
            if (ui > 2147483648) {
                return 0;
            } else {
                new_result = ui;
                new_result = -new_result;
            }
        } else {
            if (ui > 2147483647) {
                return 0;
            } else {
                new_result = ui;
            }
        }
        return new_result;
    }
};

int main()
{
  
  return 0; 
}

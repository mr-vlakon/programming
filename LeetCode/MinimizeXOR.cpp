class Solution {
public:
    int minimizeXor(int num1, int num2) {
        string first;
        string second;
        int x1 = num1;
        while (x1) {
            int tmp = x1 % 2;
            first += to_string(tmp);
            x1 /= 2;
        }
        while (first.size() != 32) {
            first.push_back('0');            
        }
        
        reverse(first.begin(), first.end());
        
        int x2 = num2;
        int cnt = 0;
        while (x2) {
            int tmp = x2 % 2;
            if (tmp == 1) {
                ++cnt;
            }
            x2 /= 2;
        }
        
        string tmp(first.size(), '0');
        for (decltype(first.size()) i = 0; i != first.size(); ++i) {
            if (first[i] == '1' && cnt > 0) {
                tmp[i] = '1';
                --cnt;
            }
        }
        reverse(first.begin(), first.end());
        reverse(tmp.begin(), tmp.end());
        for (decltype(first.size()) i = 0; i != first.size(); ++i) {
            if (first[i] == '0' && cnt > 0) {
                tmp[i] = '1';
                --cnt;
            }
        }
        
        int index = 0;
        int tmp2 = 0;
        for (const auto &e: tmp) {
            tmp2 += pow(2, index) * (e - '0');
            ++index;
        }
        
        return tmp2;        
    }
};

int main() {
  
 
  return 0;
}

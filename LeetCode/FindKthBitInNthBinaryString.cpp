class Solution {
public:
    char findKthBit(int n, int k) {
        int i = 0;
        string result = "0";
        string tmp;
        while (i != n) {
            tmp = result;
            for (auto &e: tmp) {
                if (e == '0')
                    e = '1';
                else
                    e = '0';
            }
            //cout << result << endl;
            reverse(tmp.begin(), tmp.end());
            result += "1" + tmp;
            ++i;
        }
        return *(result.cbegin() + k - 1);
    }
};

int main() {

  return 0;  
}

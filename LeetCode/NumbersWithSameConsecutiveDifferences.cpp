class Solution {
public:
    void generate(string &s) {
        if (s.size() == l) {
            result.push_back(stoi(s));
            return;
        }
        if (s.size() == 0) {
            for (int i = 1; i <= 9; ++i) {
                s.push_back(i + '0');
                generate(s);
                s.pop_back();
            }
        } else {
            for (int i = 0; i <= 9; ++i) {
                tmp = abs(s.back() - '0' - i);
                s.push_back(i + '0');
                if (tmp == diff && s.size() <= l) {
                    generate(s);
                }
                s.pop_back();
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        l = n;
        diff = k;
        string empty;
        generate(empty);
        return result;
    }
private:
    int tmp = 0;
    int diff = 0;
    vector<int> result;
    int l = 0;
};

int main() {
  
  
  
  return 0;  
}

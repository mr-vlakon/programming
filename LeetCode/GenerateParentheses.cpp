class Solution {
public:
    void generate(int i, string s, int left, int right) {
        if (i == (2 * n_)) {
            v.push_back(s);
            return;
        }
        if (i > (2 * n_)) {
            return;
        }
        s.push_back('(');
        if ((left + 1) <= n_ ) {
            generate(i + 1, s, left + 1, right);
        }
        s.pop_back();
        s.push_back(')');
        if ((right + 1) <= left && (right + 1) <= n_) {
            generate(i + 1, s, left, right + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        n_ = n;
        string empty;
        generate(0, empty, 0, 0);
        return v;
    }
private:
    vector<string> v;
    int n_ = 0;
};

int main() {
  
  
  return 0;  
}

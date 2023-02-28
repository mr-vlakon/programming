class Solution {
public:
    void generate(int i, int cnt) {
        if (i == n_) {
            if (cnt == n_)
                ++answer;
            return;
        }
        if (i > n_) {
            return;
        }
        for (int k = 1; k <= n_; ++k) {
            if (((k % (i + 1)) == 0 || (((i + 1) % k) == 0))  && ban[k] == false) {
                ban[k] = true;
                generate(i + 1, cnt + 1);
                ban[k] = false;
            }      
        } 
    }
    int countArrangement(int n) {
        n_ = n;
        ban.resize(n_ + 1, false);
        generate(0, 0);
        return answer;
    }
private:
    vector<bool> ban;
    int n_ = 0;
    int answer = 0;
};

int main() {
  
  return 0;  
}

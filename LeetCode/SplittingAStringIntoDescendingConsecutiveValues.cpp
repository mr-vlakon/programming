class Solution {
public:
    void generate(const string &s, int i, string &tmp, int cnt, string &prev) {
        if (i == s.size()) {
            if (cnt >= 1 && (tmp.size() != 0) && (stoull(prev) - stoull(tmp) == 1)) {
                status = true;
            }
            return;
        }
        tmp.push_back(s[i]);
        if (cnt == 0) {
            generate(s, i + 1, tmp, cnt, prev);
            prev = tmp;  
            tmp.pop_back();
            string empty;
            generate(s, i + 1, empty, cnt + 1, prev);
        } else {
            if ((stoull(prev) - stoull(tmp)) == 1) {
                generate(s, i + 1, tmp, cnt, prev);
                prev = tmp;             
                tmp.pop_back();
                string empty;
                generate(s, i + 1, empty, cnt + 1, prev);  
            } else {
                generate(s, i + 1, tmp, cnt, prev);
                tmp.pop_back();
            } 
        }
    }
    bool splitString(string s) {
        string empty;
        string prev;
        generate(s, 0, empty, 0, prev);
        return status;
    }
private:
    bool status = false;
};

int main() {
  
  
  return 0;  
}

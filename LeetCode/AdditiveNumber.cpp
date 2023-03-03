class Solution {
public:
    void generate(const string &s, int i, string tmp, vector<unsigned long> &v) {
        if (status) {
            return;
        }
        if (i == s.size()) {
            if (v.size() >= 2) {
                if (tmp.size() < 20) {
                    x = stoul(tmp);
                    if (x == (v.back()) + (v[v.size() - 2])) {
                        v.push_back(x);
                        if (!status) {
                            status = true;
                        }
                        v.pop_back();
                    }
                }
            } 
            return;
        }
        tmp.push_back(s[i]);
        if (tmp[0] != '0') {
            generate(s, i + 1, tmp, v);
            if (status) {
                return;
            }
        }
        tmp.pop_back();
        if (v.size() <= 1) {
            if (tmp.size() < 20) {
                v.push_back(stoul(tmp));
                tmp.resize(0);
                tmp.push_back(s[i]);
                generate(s, i + 1, tmp, v);
                if (status) {
                    return;
                }
                tmp.pop_back();
                v.pop_back();
            }
        } else {
            if (tmp.size() != 0 && tmp.size() < 20) {      
                if (tmp.size() < 20) {
                    x = stoul(tmp);
                    if (x == (v.back() + v[v.size() - 2])) {
                        v.push_back(x);
                        tmp.resize(0);
                        tmp.push_back(s[i]);
                        generate(s, i + 1, tmp, v);
                        if (status) {
                            return;
                        }
                        tmp.pop_back();
                        v.pop_back();
                    }
                }
            }
        }
    }
    bool isAdditiveNumber(string num) {
        string empty;
        vector<unsigned long> v;
        empty.push_back(num[0]);
        generate(num, 1, empty, v);
        return status;
    }
private:
    unsigned long x = 0;
    bool status = false;
};

int main() {
  
  
  return 0;  
}

class Solution {
public:
    void generate(const string &s, int i, string tmp, vector<int> &v) {
        if (status) {
            return;
        }
        if (i == s.size()) {
            if (v.size() >= 2) {
                if (tmp.size() <= 10) {
                    x = stoll(tmp);
                    y = static_cast<long long>(v.back()) +
                    static_cast<long long>(v[v.size() - 2]);
                    if (y < pow(2, 31) && x == y) {
                        v.push_back(x);
                        if (!status) {
                            result = v;
                            status = true;
                        }
                        v.pop_back();
                    }
                }
            } 
            return;
        }
        tmp.push_back(s[i]);
        if (tmp[0] != '0' && tmp.size() <= 10) {
            generate(s, i + 1, tmp, v);
            if (status) {
                return;
            }
        }
        tmp.pop_back();
        if (v.size() <= 1) {
            if (tmp.size() <= 10) {
                x = stoll(tmp);
                if (x < pow(2, 31)) {
                    v.push_back(stoi(tmp));
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
        } else {
            if (tmp.size() <= 10) {      
                x = stoll(tmp);
                if (x < pow(2, 31)) {
                    y = static_cast<long long>(v.back()) +
                        static_cast<long long>(v[v.size() - 2]);
                    if (y < pow(2, 31) && x == y) {
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
    vector<int> splitIntoFibonacci(string num) {
        string empty;
        vector<int> v;
        empty.push_back(num[0]);
        generate(num, 1, empty, v);
        return result;
    }
private:
    long long y = 0;
    long long x = 0;
    bool status = false;
    vector<int> result;
};

int main() {
  
  
  return 0;  
}

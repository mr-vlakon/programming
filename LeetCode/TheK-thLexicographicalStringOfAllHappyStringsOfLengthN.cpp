/*
class Solution {
public:
    bool isHappy(const string &s) {
        for (decltype(s.size()) i = 0; i != s.size() - 1; ++i) {
            if (s[i] == s[i + 1])
                return false;
        }
        return true;
    }
    
    void generate(const string &prefix, int n, int k) {
        if (k == 0) {
            if (isHappy(prefix)) {
                v.push_back(prefix);
            }
            return;
        }
        for (int i = 0; i < n; i++) {
            string newPrefix;
            newPrefix = prefix + set[i];
            generate(newPrefix, n, k - 1);
        }
    }
    string getHappyString(int n, int k) {
        generate("", 3, n);
        sort(v.begin(), v.end());
        if (k > v.size())
            return "";
        else
            return *(v.begin() + k - 1);
    }    
private:
    const vector<char> set = {'a', 'b', 'c'};
    vector<string> v;
};
*/

class Solution {
public:
    void generate(string &tmp) {
        if (tmp.size() == n_) {
            v.push_back(tmp);
            return;
        }
        if (tmp.size() == 0) {
            string temp = tmp;
            string temp2 = tmp;
            tmp.push_back('a');
            generate(tmp);
            temp.push_back('b');
            generate(temp);
            temp2.push_back('c');
            generate(temp2);
        } else {
            if (tmp.back() == 'a') {
                string temp = tmp;
                tmp.push_back('b');
                generate(tmp);
                temp.push_back('c');
                generate(temp);
            } else if (tmp.back() == 'b') {
                string temp = tmp;
                tmp.push_back('c');
                generate(tmp);
                temp.push_back('a');
                generate(temp);
            } else if (tmp.back() == 'c') {
                string temp = tmp;
                tmp.push_back('b');
                generate(tmp);
                temp.push_back('a');
                generate(temp);
            }
        }
    }

    string getHappyString(int n, int k) {
        string empty;
        n_ = n;
        generate(empty);
        sort(v.begin(), v.end());
        if (k > v.size()) {
            return "";
        }
        return v[k - 1];
    }
private:
    int n_ = 0;
    vector<string> v;
};

int main() {
  
  
  return 0;  
}

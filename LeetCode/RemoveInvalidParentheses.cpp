class Solution {
public:
    int minRemoveToMakeValid(const string &s) {
        int cntL = 0;
        int tmp = 0;
        for (int i = 0; i != s.size(); ++i) {
            if (s[i] == '(') {
                ++tmp;
                ++cntL;
            } else if (s[i] == ')' && 0 < cntL) {
                --tmp;
                --cntL;
            } else if (s[i] == ')') {
                ++tmp;
            } 
        }
        return tmp;
    }

    void generate(const string &s, string &str, int i, int &left, int &right) {
        if (i == s.size()) {
            if (left == right && minR == (s.size() - str.size())) {
                answer.insert(str);
            }
            return;
        }
        char prev = s[i];
        if (s[i] == '(') {
            ++left;
        } else if (s[i] == ')') {
            ++right;
        }
        str.push_back(s[i]);
        if (right <= left && str.size() <= (s.size() - minR)) {
            generate(s, str, i + 1, left, right);
        }
        if (prev == '(') {
            --left;
        } else if (prev == ')') {
            --right;
        }
        str.pop_back();
        if (right <= left && str.size() <= (s.size() - minR)) {
            generate(s, str, i + 1, left, right);  
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        string str;
        minR = minRemoveToMakeValid(s);
        int left = 0;
        int right = 0;
        generate(s, str, 0, left, right);
        return {answer.cbegin(), answer.cend()};
    }
private:
    int minR = 0;
    unordered_set<string> answer;
};
/*
class Solution {
public:
    int minRemoveToMakeValid(const string &s) {
        int cntL = 0;
        int cntR = 0;
        int tmp = 0;
        for (int i = 0; i != s.size(); ++i) {
            if (s[i] == '(') {
                ++tmp;
                ++cntL;
            } else if (s[i] == ')' && cntR < cntL) {
                --tmp;
                --cntL;
            } else if (s[i] == ')') {
                ++tmp;
            } 
        }
        return tmp;
    }

    void generate(const string &s, string &str, int i, int &left, int &right) {
        if (i == s.size()) {
            if (left == right && minR == (s.size() - str.size())) {
                answer.insert(str);
            }
            return;
        }
        char prev = s[i];
        if (s[i] == '(') {
            ++left;
        } else if (s[i] == ')') {
            ++right;
        }
        str.push_back(s[i]);
        if (right <= left && str.size() <= (s.size() - minR)) {
            generate(s, str, i + 1, left, right);
        }
        if (prev == '(') {
            --left;
        } else if (prev == ')') {
            --right;
        }
        str.pop_back();
        if (right <= left && str.size() <= (s.size() - minR)) {
            generate(s, str, i + 1, left, right);  
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        string str;
        minR = minRemoveToMakeValid(s);
        int left = 0;
        int right = 0;
        generate(s, str, 0, left, right);
        return {answer.cbegin(), answer.cend()};
    }
private:
    int minR = 0;
    unordered_set<string> answer;
};
*/
/*
class Solution {
public:
    int minRemoveToMakeValid(const string &s) {
        int cntL = 0;
        int cntR = 0;
        int tmp = 0;
        for (int i = 0; i != s.size(); ++i) {
            if (s[i] == '(') {
                ++tmp;
                ++cntL;
            } else if (s[i] == ')' && cntR < cntL) {
                --tmp;
                --cntL;
            } else if (s[i] == ')') {
                ++tmp;
            } 
        }
        return tmp;
    }

    void generate(const string &s, string &str, int i, int &left, int &right) {
        if (i == s.size()) {
            if (left == right && minR == (static_cast<int>(s.size()) - static_cast<int>(str.size()))) {
                answer.insert(str);
            }
            return;
        }
        char prev = s[i];
        if (s[i] == '(') {
            ++left;
        } else if (s[i] == ')') {
            ++right;
        }
        str.push_back(s[i]);
        if (right <= left && str.size() <= (s.size() - minR)) {
            generate(s, str, i + 1, left, right);
        }
        if (prev == '(') {
            --left;
        } else if (prev == ')') {
            --right;
        }
        str.pop_back();
        if (right <= left && str.size() <= (s.size() - minR)) {
            generate(s, str, i + 1, left, right);  
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        string str;
        minR = minRemoveToMakeValid(s);
        int left = 0;
        int right = 0;
        generate(s, str, 0, left, right);
        return {answer.cbegin(), answer.cend()};
    }
private:
    int minR = 0;
    unordered_set<string> answer;
};
*/
/*
class Solution {
public:
    int minRemoveToMakeValid(const string &s) {
        int cntL = 0;
        int cntR = 0;
        int tmp = 0;
        for (int i = 0; i != s.size(); ++i) {
            if (s[i] == '(') {
                ++tmp;
                ++cntL;
            } else if (s[i] == ')' && cntR < cntL) {
                --tmp;
                --cntL;
            } else if (s[i] == ')') {
                ++tmp;
            } 
        }
        return tmp;
    }

    void generate(const string &s, string &str, int i, int &left, int &right) {
        if (i == s.size()) {
            if (left == right && minR == (static_cast<int>(s.size()) - static_cast<int>(str.size()))) {
                answer.insert(str);
            }
            return;
        }
        char prev = s[i];
        if (s[i] == '(') {
            ++left;
        } else if (s[i] == ')') {
            ++right;
        }
        str.push_back(s[i]);
        if (right <= left) {
            generate(s, str, i + 1, left, right);
        }
        if (prev == '(') {
            --left;
        } else if (prev == ')') {
            --right;
        }
        str.pop_back();
        generate(s, str, i + 1, left, right);  
    }
    vector<string> removeInvalidParentheses(string s) {
        string str;
        minR = minRemoveToMakeValid(s);
        int left = 0;
        int right = 0;
        generate(s, str, 0, left, right);
        return {answer.cbegin(), answer.cend()};
    }
private:
    int minR = 0;
    unordered_set<string> answer;
};
*/

int main() {
  
  
  
  return 0;  
}

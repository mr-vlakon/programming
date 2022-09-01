class Solution {
public:
    string arrangeWords(string text) {
        istringstream is(text);
        string s;
        vector<string> res;
        bool status = true;
        while(is >> s) {
            if(status) {
                s[0] = tolower(s[0]);
                status = false;
            }
            res.push_back(s);
        }
        stable_sort(res.begin(), res.end(),[](const string &lhs, const string &rhs) {
           return lhs.size() < rhs.size(); 
        });
        res[0][0] = toupper(res[0][0]);
        string result;
        for (const auto &e: res) {
            result += e + " ";
        }
        string tmp(result.cbegin(), result.cend() - 1);
        return tmp;
    }
};

int main() {

  return 0;  
}

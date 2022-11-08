class Solution {
public:
    vector<string> printVertically(string s) {
        istringstream is(s);
        vector<string> res;
        string ss;
        int maxSize = 0;
        int cntWords = 0;
        while (is >> ss) {
            ++cntWords;
            res.push_back(ss);
            if (ss.size() > maxSize)
                maxSize = ss.size();
        }
        vector<string> result;
        for (auto &e: res) {
            while (e.size() < maxSize) {
                e.push_back(' ');
            }
        }
        
        int i = 0;
        while (i != maxSize) {
            string tmp;
            for (const auto &e: res) {
                tmp.push_back(e[i]);
            }
            auto pos = tmp.find_last_not_of(' ');
            tmp.erase(tmp.cbegin() + pos + 1, tmp.cend());
            result.push_back(tmp);
            ++i;
        }
        return result;
    }
};

int main() {
  
  
  
  return 0;  
}

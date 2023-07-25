class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        string tmp;
        vector<string> result;
        for (const auto &e: words) {
            for (const auto &p: e) {
                if (p == separator) {
                    if (tmp.size() != 0)
                        result.push_back(tmp);
                    tmp.resize(0);
                } else {
                    tmp.push_back(p);
                }
            }
            if (tmp.size() != 0) {
                result.push_back(tmp);
                tmp.resize(0);
            }
        }      
        return result;
    }
};

int main() {



  return 0;
}

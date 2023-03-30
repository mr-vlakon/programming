class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> um;
        string tmp;
        auto pos = 0;
        auto pos1 = 0;
        auto pos2 = 0;
        string t;
        string str;
        for (const auto &e: paths) {
            pos = e.find(' ');
            tmp = string{e.begin(), e.begin() + pos};
            while (pos != string::npos) {
                pos1 = e.find('(', pos + 1);
                pos2 = e.find(')', pos + 1);
                t = string{e.begin() + pos1 + 1, e.begin() + pos2};
                str = tmp + "/" + string{e.begin() + pos + 1, e.begin() + pos1};
                um[t].push_back(str);
                pos = e.find(' ', pos + 1);
            }    
        }
        vector<vector<string>> answer;
        for (const auto &e: um) {
            vector<string> tmp;
            for (const auto &e: e.second) {
                tmp.push_back(e);
            }
            if (tmp.size() > 1)
                answer.push_back(tmp);
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}

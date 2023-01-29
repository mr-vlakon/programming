class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> um;
        for (const auto &e: knowledge) {
            um[e[0]] = e[1];
        }
        string result;
        auto pos = 0;
        auto start = 0;
        auto prev = 0;
        auto temp = 0;
        bool status = false;
        while (pos != string::npos) {
            temp = pos;
            pos = s.find('(', pos);
            if (pos == string::npos) {
                if (status) {
                    result += string{s.begin() + temp + 1, s.end()};
                } else {
                    result += string{s.begin() + temp, s.end()};
                }
                break;
            }
            status = true;
            prev = pos;
            pos = s.find(')', pos);
            result += string{s.begin() + start, s.begin() + prev};
            start = pos + 1;
            string tmp{s.begin() + prev + 1, s.begin() + pos};
            auto it = um.find(tmp);
            if (it == um.cend()) {
                result += "?";
            } else {
                result += um[tmp];
            }
        }
        return result;
    }
};

int main() {
  
  
  
  return 0;  
}

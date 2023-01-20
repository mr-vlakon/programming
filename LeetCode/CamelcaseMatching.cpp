class Solution {
public:
    bool isCapital(const char &c) {
        return (c >= 'A' && c <= 'Z');
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> answer;
        for (int i = 0; i != queries.size(); ++i) {
            auto start = queries[i].begin();
            auto end = --queries[i].end();
            auto startPat = pattern.begin();
            while (start != queries[i].end() && startPat != pattern.end()) {
                if (isCapital(*start)) {
                    if (*start != *startPat) {
                        break;
                    }
                }
                if (*start == *startPat) {
                    ++startPat;    
                } 
                ++start;
            }
            auto it = find_if(start, queries[i].end(), [&](const char &c) {
                return (c >= 'A' && c <= 'Z');
            });
            answer.push_back((startPat == pattern.end()) && it == queries[i].end());
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}

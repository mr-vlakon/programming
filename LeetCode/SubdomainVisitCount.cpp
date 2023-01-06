class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> um;
        for (int i = 0; i != cpdomains.size(); ++i) {
            istringstream is(cpdomains[i]);
            int temp;
            is >> temp;
            string key;
            is >> key;
            um[key] += temp;
            auto pos = key.find('.');
            while (pos != string::npos) {
                string str({key.cbegin() + pos + 1, key.cend()});
                um[str] += temp;
                pos = key.find('.', pos + 1);
            }
        }
        vector<string> answer;
        for (const auto &e: um) {
            answer.push_back(to_string(e.second) + " " + e.first);
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}

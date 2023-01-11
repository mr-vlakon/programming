class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> um;
        for (const auto &e: licensePlate) {
            if (!isdigit(e) && !isspace(e)) {
                ++um[tolower(e)];
            }
        }
        string answer;
        bool firstAppear = false;
        for (const auto &e: words) {
            unordered_map<char, int> tmp;
            for (const auto &p: e) {
                ++tmp[p];
            }
            bool status = true;
            for (const auto &e: um) {
                auto it = tmp.find(e.first);
                if (it == um.cend()) {
                    status = false;
                    break;
                }
                if (it != tmp.cend() && (e.second > it->second)) {
                    status = false;
                    break;
                }
            }
            if (firstAppear == false && status == true) {
                firstAppear = true;
                answer = e;
            } else if (status && e.size() < answer.size()) {
                answer = e;
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}

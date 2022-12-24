class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string> positive;
        unordered_set<string> negative;
        
        for (const auto &e: positive_feedback) {
            positive.insert(e);
        }
        for (const auto &e: negative_feedback) {
            negative.insert(e);
        }
        vector<pair<int, int>> v;
        for (int i = 0; i != report.size(); ++i) {
            istringstream is(report[i]);
            string s;
            int score = 0;
            while (is >> s) {
                if (positive.find(s) != positive.cend()) {
                    score += 3;
                } else if (negative.find(s) != negative.cend()) {
                    score -= 1;
                }
            }
            v.push_back({score, student_id[i]});
        }
        sort(v.begin(), v.end(), [&] (pair<int, int> &lhs, pair<int, int> &rhs) {
           return lhs.second < rhs.second; 
        });
        std::stable_sort(v.begin(), v.end(), [&] (const pair<int, int> &lhs, const pair<int, int> &rhs) {
           return lhs.first > rhs.first; 
        });
        int i = 0;
        vector<int> answer;
        while (i != k) {
            answer.push_back(v[i].second);
            ++i;
        }
        return answer;
    }
};

int main() {
  
 
  return 0;
}

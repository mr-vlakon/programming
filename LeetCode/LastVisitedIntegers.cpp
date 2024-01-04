class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        int counterInt = 0;
        vector<int> answer;
        vector<int> visited;
        for (int i = 0; i != words.size(); ++i) {
            if (words[i] == "prev") {
                ++counterInt;
                int tmp = visited.size() - counterInt;
                if (tmp < 0) {
                    answer.push_back(-1);
                } else {
                    answer.push_back(visited[tmp]);
                }
            } else {
                counterInt = 0;
                visited.push_back(stoi(words[i]));
            }
        }
        return answer;
    }
};

int main()
{


  return 0;
}

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> answer;
        for (int i = 0; i != words.size(); ++i) {
            auto pos = words[i].find(x);
            if (pos != string::npos) {
                answer.push_back(i);
            }
        }
        return answer;
    }
};

int main()
{



  return 0;
}

class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> unor;
        for (int i = 0; i != s.size(); ++i) {
            string tmp;
            for (int j = i; j != s.size(); ++j) {
                if (tmp.size() != 0) {
                    if (s[j] != s[j - 1]) {
                        break;
                    }
                    else
                    {
                        tmp.push_back(s[j]);
                        ++unor[tmp];
                    }
                }
                else
                {
                    tmp.push_back(s[j]);
                    ++unor[tmp];
                }
            }
        }
        int tmpLen = 0;
        int answer = -1;
        for (const auto &e: unor) {
            if (e.second >= 3)
            {
                answer = max(answer, static_cast<int>(e.first.size()));
            }
        }
        return answer;
    }
};

int main()
{

  return 0;
}

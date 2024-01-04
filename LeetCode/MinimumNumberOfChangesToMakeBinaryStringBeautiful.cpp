class Solution {
public:
    int minChanges(string s) {
        int answer = 0;
        for (int i = 0; i != s.size(); i += 2) {
            if (s[i] != s[i + 1]) {
                ++answer;
            }
        }
        return answer;
    }
};

int main()
{


  return 0;
}

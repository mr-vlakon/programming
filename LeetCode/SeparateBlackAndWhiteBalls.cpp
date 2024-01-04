class Solution {
public:
    long long minimumSteps(string s) {
        long long answer = 0;
        int pos = -1;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0' && pos == -1) {
                pos = i;
            } else {
                if (s[i] == '1' && pos != -1) {
                    answer += pos - i;
                    --pos;
                }
            }
        }
        return answer;
    }
};

int main()
{


  return 0;
}

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> unor(26, 0);
        for (const auto &e: word)
        {
            ++unor[e - 'a'];
        }
        int answer = 0;
        int counter = 0;
        int tmp = 1;
        sort(unor.rbegin(), unor.rend());
        for (const auto &e: unor)
        {
            ++counter;
            answer += tmp*e;
            if (counter == 8)
            {
                counter = 0;
                ++tmp;
            }
        }
        return answer;
    }
};

int main()
{


  return 0;
}

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> unor(100, 0);
        for (const auto &e: nums)
        {
            ++unor[e - 1];
        }
        int maxFr = 0;
        for (const auto &e: unor)
        {
            maxFr = max(maxFr, e);
        }
        int answer = 0;
        for (int i = 0; i != unor.size(); ++i)
        {
            if (unor[i] == maxFr)
            {
                answer += unor[i];
            }
        }
        return answer;
    }
};

int main()
{


  return 0;
}

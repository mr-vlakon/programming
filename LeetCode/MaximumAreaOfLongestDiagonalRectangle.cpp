class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxD = 0.0;
        int answer = 0;
        for (const auto &e: dimensions)
        {
            if (sqrt(e[0]*e[0] + e[1]*e[1]) > maxD)
            {
                answer = e[0]*e[1];
                maxD = sqrt(e[0]*e[0] + e[1]*e[1]);
            } else if (sqrt(e[0]*e[0] + e[1]*e[1]) == maxD)
            {
                answer = max(e[0]*e[1], answer);
            }
        }
        return answer;
    }
};

int main()
{

  return 0;
}

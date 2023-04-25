class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int answer = 0;
        int maxV = 0;
        int tmp = 0;
        char prev;
        for (int i = 0; i != colors.size(); ++i) {
            if (colors[i] == prev) {
                tmp += neededTime[i];
                maxV = max(maxV, neededTime[i]);
            } else {
                tmp -= maxV;
                maxV = neededTime[i];
                answer += tmp;
                tmp = neededTime[i];
            }
            prev = colors[i];
        }
        tmp -= maxV;
        answer += tmp;
        return answer;
    }
};

int main() {
  

  return 0;
}

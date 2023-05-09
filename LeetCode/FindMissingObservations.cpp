class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sumM = accumulate(rolls.cbegin(), rolls.cend(), 0);
        int sum = mean * (n + rolls.size());
        int sumN = sum - sumM;
        int tmp = sumN / n;
        int dif = sumN - tmp*n;
        if (sumN < 0) return {};
        if (tmp > 6) return {};
        if (tmp == 6 && dif > 0) return {};
        if (tmp == 0) return {};
        vector<int> answer;
        while (sumN > 0) {
            answer.push_back(tmp + ((dif) ? 1 : 0));
            sumN -= tmp + ((dif) ? 1 : 0);
            if (dif > 0) -- dif;    
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        unordered_set<long long> us;
        long long answer = 0;
        for (int i = 0; i != skill.size() / 2; ++i) {
            us.insert(skill[i] + skill[skill.size() - i - 1]);
            answer += skill[i] * skill[skill.size() - i - 1];
        }
        if (us.size() > 1)
            return -1;
        
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}

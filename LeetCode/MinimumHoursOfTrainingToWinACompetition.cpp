class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        long long sum = accumulate(energy.cbegin(), energy.cend(), 0LL);
        int answer = 0;
        if (sum >= initialEnergy) {
            answer += sum - initialEnergy + 1;
        }
        for (int i = 0; i != experience.size(); ++i) {
            if (experience[i] >= initialExperience) {
                answer += experience[i] - initialExperience + 1;
                initialExperience += (experience[i] - initialExperience + 1) + experience[i];
            } else {
                initialExperience += experience[i];
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}

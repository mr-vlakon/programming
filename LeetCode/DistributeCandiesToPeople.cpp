class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> answer(num_people);
        int i = 1;
        while (true) {
            bool status = false;
            for (int j = 0; j != answer.size(); ++j) {
                if (candies > 0 && candies > i) {
                    answer[j] += i;
                } else {
                    status = true;
                    answer[j] += candies;
                    break;
                }
                candies -= i;
                ++i;
            }
            if (status)
                break;
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}

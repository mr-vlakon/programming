class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        auto start = people.begin();
        auto end = --people.end();
        int answer = 0;
        while (start <= end) {
            if (start == end) {
                ++answer;
                break;
            }
            if ((*start + *end) <= limit) {
                ++start;
                --end;
                ++answer;
            } else if ((*start + *end) > limit) {
                --end;
                ++answer;
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  
  return 0;   
}

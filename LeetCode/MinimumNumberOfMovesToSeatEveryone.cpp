class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(students.begin(), students.end());
        sort(seats.begin(), seats.end());
        int answer = 0;
        for (decltype(students.size()) i = 0; i != students.size(); ++i) {
            answer += abs(students[i] - seats[i]);
        }
        return answer;
        
    }
};

int main() {
  
  return 0;  
}

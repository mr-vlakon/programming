class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> right(seats.size(), -1);
        for (int i = seats.size() - 1; i >= 0; --i) {
            if (seats[i]) {
                right[i] = i;
            } else {
                if (i != (seats.size() - 1))
                    right[i] = right[i + 1]; 
            }
        }
        int answer = 0;
        int tmp = 0;
        int closestLeft = -1000000;
        for (int i = 0; i != seats.size(); ++i) {
            if (!seats[i]) {
                tmp = min(abs(i - right[i]), abs(i - closestLeft));
                answer = max(tmp, answer);
            } else {
                closestLeft = i;
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int answer = 0;
        int sum = accumulate(distance.cbegin(), distance.cend(), 0);
        for (int i = min(start, destination); i < max(start, destination); ++i) {
            answer += distance[i];
        }
        return min(answer, sum - answer);
    }
};

int main() {
  
  return 0;  
}

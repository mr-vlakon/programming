class Solution {
public:
    int countCollisions(string directions) {
        int answer = 0;
        char prev = 'X';
        int x = 0;
        for (int i = 0; i != directions.size(); ++i) {
            if (prev == 'X') {
                if (directions[i] != 'L') {
                    prev = directions[i];
                    x = 1;
                }
            } else if ((prev == 'R' && directions[i] == 'L') || (prev == 'S' && directions[i] == 'L') || (prev == 'R' && directions[i] == 'S')){
                if (prev == 'R' && directions[i] == 'L') {
                    answer += 2 + x - 1;
                    x = 1;
                    prev = 'S';
                } else if (prev == 'S' && directions[i] == 'L'){
                    answer += 1;
                } else if (prev == 'R' && directions[i] == 'S') {
                    answer += x;
                    x = 1;
                    prev = 'S';
                }
            } else {
                if (directions[i] != 'L') {
                    if (prev == directions[i]) {
                        x = x + 1;
                    } else {
                        prev = directions[i];
                        x = 1;
                    }
                }
            }
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}

class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        reverse(firstWord.begin(), firstWord.end());
        int first = 0;
        int cnt = 1;
        for (decltype(firstWord.size()) i = 0; i != firstWord.size(); ++i) {
            first += cnt * (firstWord[i] - 'a');
            cnt *= 10;
        }
        
        reverse(secondWord.begin(), secondWord.end());
        int second = 0;
        cnt = 1;
        for (decltype(secondWord.size()) i = 0; i != secondWord.size(); ++i) {
            second += cnt * (secondWord[i] - 'a');
            cnt *= 10;
        }        

        reverse(targetWord.begin(), targetWord.end());
        int target = 0;
        cnt = 1;
        for (decltype(targetWord.size()) i = 0; i != targetWord.size(); ++i) {
            target += cnt * (targetWord[i] - 'a');
            cnt *= 10;
        }
        return (first + second) == target;
    }
};

int main() {
  
  return 0;  
}

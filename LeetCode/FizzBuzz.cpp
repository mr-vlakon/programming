class Solution {
public:
    vector<string> fizzBuzz(int n) {
        int i = 1;
        vector<string> result;
        while(i <= n) {
            if((i % 3 == 0) && (i % 5 == 0)) {
                result.push_back("FizzBuzz");
            } else if (i % 3 == 0) {
                result.push_back("Fizz");
            } else if (i % 5 == 0) {
                result.push_back("Buzz");
            } else {
                result.push_back(to_string(i));
            }
            ++i;
        } 
        return result;
    }
};

int main() {
  
  return 0;  
}

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        auto positive1 = num1.find('+', 1);
        auto negative1 = num1.find('-', 1);
        int pos1 = 0;
        int x1 = 0;
        if ((negative1 == string::npos) || (positive1 < negative1)) {
            pos1 = positive1 + 1;
            x1 = stoi(string{num1.cbegin(), num1.cbegin() + positive1});
        } else {
            pos1 = negative1 + 1;
            x1 = stoi(string{num1.cbegin(), num1.cbegin() + negative1});    
        }
        auto positive2 = num2.find('+', 1);
        auto negative2 = num2.find('-', 1);
        int pos2 = 0;
        int x2 = 0;
        if ((negative2 == string::npos) || (positive2 < negative2)) {
            pos2 = positive2 + 1;
            x2 = stoi(string{num2.cbegin(), num2.cbegin() + positive2});
        } else {
            pos2 = negative2 + 1;
            x2 = stoi(string{num2.cbegin(), num2.cbegin() + negative2});    
        }   
        auto findI1 = num1.find('i', pos1);
        int y1 = stoi(string{num1.cbegin() + pos1, num1.cbegin() + findI1});
        auto findI2 = num2.find('i', pos2);
        int y2 = stoi(string{num2.cbegin() + pos2, num2.cbegin() + findI2});
        string answer;
        answer = to_string(x1*x2 - y1*y2);
        answer += '+';
        answer += to_string(x1*y2 + y1*x2) + 'i';      
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}

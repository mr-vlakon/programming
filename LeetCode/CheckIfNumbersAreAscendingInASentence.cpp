class Solution {
public:
    bool areNumbersAscending(string s) {
        istringstream is(s);
        string s1;
        vector<int> result;
        while(is >> s1) {
            bool status = 
                (s1.find_first_not_of( "0123456789" ) == std::string::npos);
            if (status) {
                result.push_back(stoi(s1));
            }
        }
        return is_sorted(result.begin(), result.end(), 
                         [](const int &lhs, const int &rhs) {
                             return lhs <= rhs;
                         });
    }
};

int main() {
  
  return 0;  
}

class Solution {
public:
    string defangIPaddr(string address) {
        auto pos = address.find('.');
        string res;
        while (pos != string::npos) {
            res += string(address.cbegin(), address.cbegin() + pos);
            res += "[.]";
            address.erase(address.cbegin(), address.cbegin() + pos + 1);
            pos = address.find('.');
            if (pos == string::npos) {
                res += address;
                break;
            }
        }
        return res;
        
    }
};

int main() {
  
  
  
  return 0;  
}

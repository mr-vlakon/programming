class Solution {
public:
    int minPartitions(string n) {
        return *max_element(n.cbegin(), n.cend()) - '0';
    }
};

int main() {
  
  
  return 0;  
}

class NumberContainers {
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        m[index] = number;
    }
    
    int find(int number) {
        auto it = find_if(m.cbegin(), m.cend(), [=](const pair<int,int> &x) {
           return number == x.second; 
        });
        if(it == m.cend())
            return -1;
        return it->first;
    }
private:
    map<int, int> m;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

int main() {
  
  
  return 0;  
}

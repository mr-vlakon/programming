class Solution {
public:
    string interpret(string command) {
        auto pos1 = command.find("()");
        auto pos2 = command.find("(al)");
        
        while (pos1 != string::npos || pos2 != string::npos) {
            if (pos1 != string::npos)
                command.replace(pos1, 2, "o");
            
            pos2 = command.find("(al)");
            if (pos2 != string::npos)
                command.replace(pos2, 4, "al");
            pos1 = command.find("()");
        
        }
        return command;
    }
};

int main() {
  
  
  return 0;  
}

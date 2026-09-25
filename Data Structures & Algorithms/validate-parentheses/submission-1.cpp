class Solution {
public:
    bool isValid(string s) {
        stack<char> p;

        for(char c : s){
            if (c == '{' || c == '(' || c == '['){
                p.push(c);
            }
            else if (p.empty()){
                return false;
            }
            else if(c == '}' && p.top() == '{'){
                p.pop();
            }
            else if(c == ')' && p.top() == '('){
                p.pop();
            }
            else if(c == ']' && p.top() == '['){
                p.pop();
            }
            else{
                return false;
            }
        }

        if(!p.empty()){
            return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> check;
        for(int i=0;i<s.size();i++){
            char r=s[i];
            if(r=='(' || r=='{' || r=='['){
                check.push(r);
            }else if(r=='}' || r==']' || r==')'){
                if(!check.empty()){
                    if(r==')' && check.top()=='('){
                        check.pop();
                    }
                    else if(r==']' && check.top()=='['){
                        check.pop();
                    }
                    else if(r=='}' && check.top()=='{'){
                        check.pop();
                    }
                    else{
                        return false;
                    }
                }else if(check.empty()){
                    return false;
                }
            }
        }
        if(!check.empty()){
            return false;
        }
        return true;
    }
};

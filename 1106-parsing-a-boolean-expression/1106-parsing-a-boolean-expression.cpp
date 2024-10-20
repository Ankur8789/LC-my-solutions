class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<char> action,type;
        int n = exp.size();
        int i = 0;
        while(i < n){
            if(exp[i] == '|' || exp[i] == '&' || exp[i] == '!')
                action.push(exp[i]);
            else if(exp[i] == 'f' || exp[i] == 't' || exp[i] == ',' || exp[i] == '('){
                if(exp[i] !=',')
                    type.push(exp[i]);
            }
            else if(exp[i] == ')'){
                int tr = 0,fl = 0;
                while(type.size() && type.top()!='('){
                    if(type.top() == 'f')
                        fl++;
                    else
                        tr++;
                    type.pop();
                }
                type.pop();
                char opr = action.top();
                action.pop();
                if(opr == '|'){
                    if(tr)
                        type.push('t');
                    else
                        type.push('f');
                }
                else if(opr == '!'){
                    if(tr)
                        type.push('f');
                    else
                        type.push('t');
                }
                else{
                    if(fl)
                        type.push('f');
                    else
                        type.push('t');
                }
            }
            i++;
        }
       
        return (type.top()=='f')?0:1;
    }
};
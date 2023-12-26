#include<iostream>
#include<string>
#include<vector>
using namespace std;

template <class T>
class stack : public vector<T> {
    vector<T> st;
public:
    void push(T n) {
        st.push_back(n);
    }
    int top() {
        return st[st.size()-1];
    }
    void pop() {
        st.pop_back();
    }
    bool empty() {
        return st.empty();
    }
};

int priority(char op){
    if(op == '+'||op == '-')
    return 1;
    if(op == '*'||op == '/')
    return 2;
    return 0;
}

int applyOp(int a, int b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}
int evaluate(string tokens){
    int i;
    
    stack<int> values;
    
    stack<char> ops;
    
    for(i = 0; i < tokens.length(); i++){
        
        if(tokens[i] == ' ')
            continue;
        
        else if(tokens[i] == '('){
            ops.push(tokens[i]);
        }
        
        else if(isdigit(tokens[i])){
            int val = 0;
            
            while(i < tokens.length() && 
                        isdigit(tokens[i]))
            {
                val = (val*10) + (tokens[i]-'0');
                i++;
            }
            
            values.push(val);
            
            i--;
        }
        
        else if(tokens[i] == ')')
        {
            while(!ops.empty() && ops.top() != '(')
            {
                int val2 = values.top();
                values.pop();
                
                int val1 = values.top();
                values.pop();
                
                char op = ops.top();
                ops.pop();
                
                values.push(applyOp(val1, val2, op));
            }
            
            if(!ops.empty())
               ops.pop();
        }
        
        else
        {
            while(!ops.empty() && priority(ops.top())
                                >= priority(tokens[i])){
                int val2 = values.top();
                values.pop();
                
                int val1 = values.top();
                values.pop();
                
                char op = ops.top();
                ops.pop();
                
                values.push(applyOp(val1, val2, op));
            }
            
            ops.push(tokens[i]);
        }
    }
    
    while(!ops.empty()){
        int val2 = values.top();
        values.pop();
                
        int val1 = values.top();
        values.pop();
                
        char op = ops.top();
        ops.pop();
                
        values.push(applyOp(val1, val2, op));
    }
    
    return values.top();
}

int main() {
    cout << "Input" << endl;
    string exp;
    cin >> exp;
    cout << "Output" << endl;
    cout << "=" << evaluate(exp) << endl;
    cout << "end" ;
    return 0;
}

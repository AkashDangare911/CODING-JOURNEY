class Solution {
private:
    bool isOperator(char c)
    {   
        if(c=='&' || c=='|' || c=='!'){
            return true;
        }
        return false;
    }
public:
    bool parseBoolExpr(string exp) {
        stack<char> st;
        vector<char> ops;

        for(char c:exp)
        {
            if(isOperator(c)){
                ops.push_back(c);
            }
            else if(c=='(')
                st.push(c);
            else if(c>='a' && c<='z'){
                c=='f' ? st.push(0): st.push(1);
            }

            // ready to evaluate
            else if(c==')'){
                bool ans = st.top();
                st.pop();
                char o = ops.back();

                if(o=='!'){
                    // st.pop();
                    ans = !ans;
                }
                else
                {
                    while(!st.empty() && st.top()!='('){
                        int t = st.top();

                        if(o=='&')
                            ans = ans&t;
                        else if(o=='|')
                            ans = ans|t;
                        else
                            ans = !t;

                        st.pop();
                    }
                }
                st.pop();   //popping '('
                st.push(ans);
                ops.pop_back(); // popping previous operator
            }
        }

        return st.top();
    }

    // "!(&(f,t))"
    // ops => !
    // st  => 
    // ans => 1
};
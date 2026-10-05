class Solution {
  public:
  
    int check(char ch){
        if(ch=='^'){
            return 3 ;
        }
        if(ch=='*' || ch== '/'){
            return 2 ;
        }
        if(ch=='+' || ch== '-'){
            return 1 ;
        }
        return -1 ;
    }
    string infixToPostfix(string& s) {
        // code here
        stack<char> st ;
        string ans= "" ;
        for(char i: s){
            if( ('a'<= i && i<= 'z') || 
                ('A'<= i && i<= 'Z') || 
                ('0'<= i && i<='9')){
                    ans+= i ;
                }
            else if(i == '('){
                st.push(i) ;
            } else if(i== ')'){
                while(st.top()!='('){
                    ans+= st.top() ;
                    st.pop() ;
                }
                st.pop() ;
            } else {
                if(st.empty() || (st.top()=='^' && i=='^')){
                    st.push(i) ;
                } else {
                    while(!st.empty() && check(i)<= check(st.top())){
                        ans+= st.top() ;
                        st.pop() ;
                    }
                    st.push(i) ;
                }
            }
        }
        
        while(!st.empty()){
            ans+= st.top() ;
            st.pop() ;
        }
        
        return ans ;
    }
};

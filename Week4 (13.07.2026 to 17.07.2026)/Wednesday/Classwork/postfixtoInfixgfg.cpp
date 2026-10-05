class Solution {
  public:
    string postToInfix(string &exp) {
        // Write your code here
        stack<string> st ;
        string ans= "" ;
        string first, second ;
        string s= "" ;
        for(char i: exp){
            s= "" ;
            if(('a'<=i && i<='z') || ('A'<=i && i<='Z') || 
                ('0'<=i && i<='9')){
                s  += i ;
                st.push(s) ;
            } else {
                first = st.top() ;
                st.pop() ;
                second = st.top() ;
                st.pop() ;
                s = "(" + second + i + first + ")" ;
                st.push(s) ;
            }
        }
        while(!st.empty()){
            ans+= st.top() ;
            st.pop() ;
        }
        return ans ;
    }
};
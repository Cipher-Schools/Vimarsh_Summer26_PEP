class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st ;
        int first = 0 ;
        int second = 0 ;
        int temp = 0 ;
        for(string s: tokens){
            if(s=="*" || s=="/" || s== "+" || s=="-"){
                first = st.top() ;
                st.pop() ;
                second = st.top() ;
                st.pop() ;
                if(s=="*"){
                    temp = first * second ;
                } else if(s=="/") {
                    temp = second/first ;
                } else if(s=="+") {
                    temp = first + second ;
                } else {
                    temp = second - first ;
                }
                st.push(temp) ;
            } else {
                st.push(stoi(s)) ;
            }
        }

        return st.top() ;
    }
};
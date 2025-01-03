class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty()) return false;
                char ch =st.top();
                st.pop();
                if((s[i]==')' && ch =='(') || (s[i]==']' && ch=='[') || (s[i]=='}' && ch=='{'))
                {
                   continue;
                }
                else
                {
                    return false;
                }
            }
        }
        return st.empty();
        
        
    }
};

/*
string ka ek ek char stack me dalege or uska pair dhudege..agr hai toh true wrna false...
*/

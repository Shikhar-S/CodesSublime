//ONP-SPOJ and Codechef
#include <stack>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		string x;
	    cin>>x;
	    int n=x.length();
	    stack<string> st;
	    stack<char> bracket;
	    for(int i=0;i<n;i++)
	    {
	        char ch=x[i];
	        if(ch=='(')
	        {
	            bracket.push(ch);
	        }
	        else if(ch==')')
	        {
	            bracket.pop();
	            string t=st.top();st.pop();
	            string temp=st.top();st.pop();
	            int k=temp.length();
	            temp=temp.substr(0,k-1)+t+temp[k-1];
	            if(x[i+1]=='+' || x[i+1]=='-' || x[i+1]=='*' || x[i+1]=='/' || x[i+1]=='^')
	            	{
	            		temp=temp+x.substr(i+1,1);
	            		i++;
	            	}
	           // cout<<temp<<endl;
	            st.push(temp);
	        }
	        else
	        {
	            if(i<n && (x[i+1]=='+' || x[i+1]=='-' || x[i+1]=='*' || x[i+1]=='/' || x[i+1]=='^'))
	            {
	                string temp=x.substr(i,2);
	                st.push(temp);
	                i+=1;
	            }
	            else
	            {
	                st.push(x.substr(i,1));
	            }
	        }
	    }
	    cout<<st.top()<<endl;
	}
    
}
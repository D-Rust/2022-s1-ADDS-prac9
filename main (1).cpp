#include <iostream>
#include <stack>
#include <string>
#include <sstream> 
using namespace std;
bool isOp(char x) { 
switch (x) {
case '+':
case '-':
case '/':
case '*':
return true;
}
return false;
}

int eval(signed int interger1,signed int interger2,char exp)
{
int val;
if(exp=='+')
val=interger1+interger2;
else if(exp=='-')
val=interger1-interger2;
else if(exp=='/')
val=interger1/interger2;
else if(exp=='*')
val=interger1*interger2;

return val;
}


string prefixToInfix(string prefix_str) {
stack<string> s;
stack<int> s2;

int len = prefix_str.size();


for (int i = len - 1; i >= 0; i--) {


if (isOp(prefix_str[i])) {
string operands1,op2;
signed int interger1,interger2;

if(!s.empty())
{

operands1 = s.top(); s.pop();
interger1=s2.top();s2.pop();
if(!s.empty())
{

op2 = s.top(); s.pop();
interger2=s2.top();s2.pop();
}
else
{

cout<<"Error"<<endl;
break;
}
}
else
{
cout<<"Error"<<endl;
break;
}


string temp_str = "(" + operands1 + prefix_str[i] + op2 + ")";

signed int val=eval(interger1,interger2,prefix_str[i]);

s.push(temp_str);
s2.push(val);
}


else {


s.push(string(1, prefix_str[i]));
s2.push(prefix_str[i]-'0');
}
}


if(s.size()>1)
{
cout<<"Error";
exit(0);
}
else
{
ostringstream o;
o <<s2.top();
string res=s.top()+"="+o.str();
return res;
}
}


int main() {
string prefix_str;
cout<<"enter a prefix expression:"<<endl;
cin>>prefix_str;
cout << prefixToInfix(prefix_str);
return 0;
}
#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main()
{
    string s;
    queue<string> Q;
    while(cin>>s)
    {
        if(s=="Push")
        {
            cin>>s;
            Q.push(s);
        }
        else if(s=="Pop")
        {
            if(Q.size()>0) Q.pop();
        }
        else
        {
            if(Q.size()==0) cout<< "empty"<<endl;
            else cout<<Q.front()<<endl;
        }
    }
}

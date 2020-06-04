#include<bits/stdc++.h>
using namespace std;
void calc(vector<int> &fib,int key)
{
    fib.push_back(0);
    fib.push_back(1);
    fib.push_back(1);
    int i=3;
    while(1)
    {
        int next=fib[i-1]+fib[i-2];
        if(next>key)
        return;
        fib.push_back(next);
        i++;
    }
}
int find(int key)
{
    vector<int> fib;
    calc(fib,key);
    int count=1;
    int j=fib.size()-1;
    key=key%fib[j];
    j--;
    while(key>0)
    {
        count+=(key/fib[j]);
        key%=fib[j];
        j--;
    }
    
    return count;
}
int main(){
    int key;
    cin>>key;
    cout<<find(key);
}

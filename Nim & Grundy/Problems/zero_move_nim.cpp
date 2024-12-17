#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int xs=0;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x;
            if(x%2==0)
                y=x-1;
            else y=x+1;
            xs^=y;
        }
        if(xs!=0)
            cout<<"W"<<endl;
        else cout<<"L"<<endl;
    }
    return 0;
}

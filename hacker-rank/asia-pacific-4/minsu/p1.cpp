
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char str[1001000];
    int d;
    cin>>str>>d;
    int cnt=0,ans=0;
    int l=(int)strlen(str);
    for(int i=0;i<l;i++){
        if(str[i]=='0'){
            cnt++;
        }
        else{
            ans+=(cnt/d);
            cnt=0;
        }
    }
    ans+=(cnt/d);
    cout<<ans<<endl;
}
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int digsum=0;
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            while(a){
                digsum+=a%10;
                a/=10;
            }
        }
        if(digsum%3==0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
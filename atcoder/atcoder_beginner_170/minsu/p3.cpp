#include<iostream>
using namespace std;
int  main(){
    int x,n;
    cin>>x;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int c=0,ans;
    while(1){
        bool flag=false;
        for(int i=0;i<n;i++){
            if(x-c==arr[i]){
                flag=true;
                break;
            }
        }
        if(!flag){
            ans=x-c;
            break;
        }
        flag=false;
        for(int i=0;i<n;i++){
            if(x+c==arr[i]){
                flag=true;
                c++;
                break;
            }
        }
        if(!flag){
            ans=x+c;
            break;
        }
    }
    cout<<ans<<endl;
}
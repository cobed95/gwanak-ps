#include <iostream>
using namespace std;
int main(){
    int i,ans=0;
    for(int j=0;j<5;j++){
        cin>>i;
        if(i==0) ans=j+1;
    }
    cout<<ans<<endl;
}
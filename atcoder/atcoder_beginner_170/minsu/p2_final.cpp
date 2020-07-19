//passed
#include <iostream>
using namespace std;

int main(){
    int x,y;
    cin>>x;
    cin>>y;
    int a=4*x-y;
    if((a%2==0)&&(a>=0)&&(a<=2*x)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
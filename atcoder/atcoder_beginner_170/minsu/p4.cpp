#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> A,B;
    int f=0,cnt=0,i,j;
    for(i=0;i<n;i++){
        int t;
        cin>>t;
        B.push_back(t);
        for(j=0;j<f;j++){
            if(A[j]==t){
                cnt++;
            }
            else if(t%A[j]==0){
                break;
            }
            else if(A[j]%t==0){
                A[j]=t;
            }
        }
        if(j==f){
            A.push_back(t);
            sort(A.begin(),A.end());
            A.erase(unique(A.begin(),A.end()),A.end());
            f=A.size();   
        }
    }
    sort(A.begin(),A.end());
    A.erase(unique(A.begin(),A.end()),A.end());
    f=A.size();
    
    cout<<f<<endl;
}
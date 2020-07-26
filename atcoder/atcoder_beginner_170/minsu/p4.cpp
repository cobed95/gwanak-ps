//time limit exceeded
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> A;
    int B[200000];
    int f=0,i,j;
    for(i=0;i<n;i++){
        int t;
        cin>>t;
        B[i]=t;
        for(j=0;j<f;j++){
            if(A[j]==t){
                break;
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
    vector<int> fi;
    for(int i=0;i<f;i++){
        fi.push_back(0);
    }
    for(int i=0;i<f;i++){
        for(int j=0;j<n;j++){
            if(A[i]==B[j]) fi[i]++;
            if(fi[i]>1) break;
        }
    }
    int cnt=0;
    for(int i=0;i<f;i++){
        if(fi[i]>1) cnt++;
    }
    cout<<f-cnt<<endl;
}
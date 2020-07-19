//not finished
#include<iostream>
#include<vector>
using namespace std;
class infant{
    public: 
    int kind;
    int rate;
    infant(int ki,int ra){
        kind=ki;
        rate=ra;
    }
};
class kind{
    public:
     int num;
     vector<infant> chi;
     kind(int n,int ra){
         num=n;
         chi.push_back(infant(n,ra));
     }
};
int main(){
    int n,q;
    int a[20000],b[20000];
    vector<kind> kinds;
    int size,j;
    for(int i=0;i<n;i++){
        size=kinds.size();
        int t1,t2;
        cin>>t1;
        cin>>t2;
        for(j=0;j<size;j++){
            if(kinds[j].num==t2){
                kinds[j].chi.push_back(infant(t2,t1));
            }
        }
        if(j==size){
            kinds.push_back(kind(t2,t1));
        }
    }

    for(int i=0;i<q;i++){
        int t1,t2;
        cin>>t1;
        cin>>t2;
        for()
    }
}
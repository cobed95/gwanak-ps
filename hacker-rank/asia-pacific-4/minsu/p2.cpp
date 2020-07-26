#include<iostream>
#include<set>
using namespace std;

int main()
{
    multiset<int> boy,girl,both;
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int in;
        for(int j=0;j<n;j++){
            cin>>in;
            boy.insert(in);
        }
        for(int j=0;j<n;j++){
            cin>>in;
            girl.insert(in);
        }
        int b=0,g=0;
        int j;
        bool flag=true;
        while(!boy.empty()||!girl.empty()){
            if(boy.empty()||girl.empty()){
                if(boy.empty()){
                    if(girl.size()>1){
                        flag=false;
                    }
                    else flag=true;
                    break;
                }
                else{
                    if(boy.size()>1){
                        flag=false;
                    }
                    else flag=true;
                    break;
                }
            }
            if(b<2&&g<2){
                int bb=0,gg=0;
                if(*boy.begin()==*girl.begin()){
                    int same=*boy.begin();
                    int bb=0,gg=0;
                    bb=boy.count(same);
                    gg=girl.count(same);
                    boy.erase(boy.lower_bound(same),boy.upper_bound(same));
                    girl.erase(girl.lower_bound(same),girl.upper_bound(same));
                    if(bb==gg){
                        b=0;
                        g=0;
                    }
                    else{
                        if(bb-gg>2||bb-gg<-2){
                            flag=false;
                            break;
                        }
                        else{
                            if(bb>gg){
                                if(b!=0){
                                    flag=false;
                                    break;
                                }
                                b=1;
                                g=0;
                            }
                            else{
                                if(g!=0){
                                    flag=false;
                                    break;
                                }
                                b=0;
                                g=1;
                            }
                        }
                    }

                }
                else if(*boy.begin()<*girl.begin()){
                    bb=boy.count(*boy.begin());
                    if(b+bb>1){
                        flag=false;
                        break;
                    }
                    else{
                        b+=bb;
                        g=0;
                        boy.erase(boy.lower_bound(*boy.begin()),boy.upper_bound(*boy.begin()));
                    }
                }
                else{
                    gg=girl.count(*girl.begin());
                    if(g+gg>1){
                        flag=false;
                        break;
                    }
                    else{
                        g+=gg;
                        b=0;
                        girl.erase(girl.lower_bound(*girl.begin()),girl.upper_bound(*girl.begin()));
                    }
                }
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        boy.clear();
        girl.clear();
    }
}
    #include<iostream>
    #include<map>
    #include<set>
    #include<fstream>
    using namespace std;
    int main()
    {
        ofstream fout;
        fout.open("out.txt");
        map<string,string>m;
        multiset<string> ms;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            string str;
            cin>>str;
            bool done=false;
            if(ms.count(str)){
                fout<<str<<" "<<ms.count(str)+1<<endl;
                done=true;
            }

            ms.insert(str);
            int l=str.length();
            bool flag=false;
            string temp;
            int j;
            for(j=0;j<l;j++){
                if(done)break;
                if(!m.count(str.substr(0,j+1))){
                    //cout<<"]"<<str.substr(0,j+1)<<endl;
                    int t=j;
                    while(t<str.length()&&t<temp.length()&&str.at(t)==temp.at(t)) t++;
                    while(m.count(str.substr(0,t+1))&&t<str.length()) t++;
                    //cout<<"["<<str<<","<<temp<<endl;
                    fout<<str.substr(0,t+1)<<endl;
                    flag=true;
                    m.insert(make_pair(str.substr(0,t+1),str));
                    break;
                }
                else{
                    temp=m.find(str.substr(0,j+1))->second;
                }
            }
            if(j==l||(!flag&&!done)) fout<<str<<endl;
        }
        fout.close();
        
    }
#include<iostream>
using namespace std;
int fin(int,int,int);
int arr[310][310];
bool barr[310][310];
int m,n;
int main()
{
    
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[n][m];
        }
    }
    int ans=fin(1,1,arr[1][1]);
    cout<<ans<<endl;

}

int fin(int x, int y,int z){
    if(x==n&&y==m){
        int t=(z-arr[x][y]>0)?z-arr[x][y]:arr[x][y]-z;
        return t;
    }
    else if(x<1||y<1||x>n||y>m){
        return 123456;
    }
    else if(barr[x][y]){
        return 123456;
    }
    else{
        int t=(z-arr[x][y]>0)?z-arr[x][y]:arr[x][y]-z;
        barr[x][y]=true;
        int temp[4][2]={{1,1},{-1,-1},{-1,1},{1,-1}};
        int min=123456;
        for(int i=0;i<4;i++){
            int tt=fin(x+temp[i][0],y+temp[i][1],arr[x][y]);
            cout<<">"<<tt<<endl;
            if(min>tt) min=tt;
        }
        barr[x][y]=false;
        if(min<=100000&&min>t) return min;
        else return t;
    }
}

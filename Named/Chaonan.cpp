#include<bits/stdc++.h>
using namespace std;
//02/03/04
void solve(){
    int y,m,d;
    char ch;
    scanf("%d%c%d%c%d",&y,&ch,&m,&ch,&d);
    int a[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    auto is_run=[](int y){return (y%4==0&&y%100)||(y%400==0);};
    auto isok=[&](int y,int m,int d){
        if(m>=1&&m<=12){
            if(m==2){
                if(is_run(y)) {
                    if(d>=1&&d<=29) return 1;
                    return 0;
                }
                else{
                    if(d>=1&&d<=28) return 1;
                    return 0;
                }
            }
            else{
                if(d>=1&&d<=a[m]) return 1;
                return 0;
            }
        }
        return 0;
    };
    vector<array<int,3> >v;
    if(isok(y,m,d)) v.push_back({y,m,d});
    if(isok(d,y,m)) v.push_back({d,y,m});
    if(isok(d,m,y)) v.push_back({d,m,y});
    sort(v.begin(),v.end());
    int len=unique(v.begin(),v.end())-v.begin();
    for(int i=0;i<len;i++) {
        if(v[i][0]<60) printf("20%02d-%02d-%02d\n",v[i][0],v[i][1],v[i][2]);
        else printf("19%02d-%02d-%02d\n",v[i][0],v[i][1],v[i][2]);
    }
}
int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
    int T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}

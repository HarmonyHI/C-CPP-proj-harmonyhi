#include<bits/stdc++.h>
using namespace std;
class block{
public:
    int day;
    int spdday;
    int ldpos;
    bool able;
    block(){
        able=true;
    }
};
void swp(block &a,block &b){
    int q,w,e;
    bool r;
    q=a.day;
    w=a.spdday;
    e=a.ldpos;
    r=a.able;
    a.day=b.day;
    a.spdday=b.spdday;
    a.ldpos=b.ldpos;
    a.able=b.able;
    b.day=q;
    b.spdday=w;
    b.ldpos=e;
    b.able=r;
}
void show(block *arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i].day<<" "<<arr[i].spdday<<" "<<arr[i].ldpos<<" "<<arr[i].able<<endl;
    }
}
int main(){
    int n;
    int src;
    int minneed;
    cin>>n>>src>>minneed;
    block blkarr[100010];
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        blkarr[i].day=a;
        blkarr[i].spdday=b;
        blkarr[i].ldpos=i;
    }
    for(int i=0;i<n;i++){
        for(int ii=0;ii<n-1;ii++){
            if(blkarr[ii].spdday>blkarr[ii+1].spdday){
                swp(blkarr[ii],blkarr[ii+1]);
            }
        }
    }
    while(1){
        int srcbkp=src;
        int mxdy=blkarr[0].day;
        int mxdpos=0;
        for(int i=1;i<n;i++){
            if(blkarr[i].day>mxdy&&blkarr[i].able){
                mxdy=blkarr[i].day;
                mxdpos=i;
            }
        }
        if(blkarr[mxdpos].spdday<=src&&blkarr[mxdpos].day>2){
            src-=blkarr[mxdpos].spdday;
            blkarr[mxdpos].day--;
        }
        else{
            blkarr[mxdpos].able=false;
        }
        if(srcbkp==src){
            break;
        }
    }
    int ans=blkarr[0].day;
    for(int i=1;i<n;i++){
        if(blkarr[i].day>ans){
            ans=blkarr[i].day;
        }
    }
    cout<<ans;
}

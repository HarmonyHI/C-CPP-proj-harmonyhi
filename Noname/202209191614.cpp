#include<bits/stdc++.h>
using namespace std;
int multi_func(int *ans_arr,int *serial_arr, int n){
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=ans_arr[i]*serial_arr[i];
    }
    return ans;
}
bool all_one(int *data,int n){

    for(int i=0;i<n;i++){
        if(data[i]==false){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    int m;
    int q;
    cin>>n>>m>>q;
    int people[n]={0};
    int work[m+1]={0};
    for(int i=0;i<q;i++){
//add
        int op;
        cin>>op;
        if(op==1){
            int l,r,x;
            cin>>l>>r>>x;
            for(int ii=l-1;ii<=r-1;ii++){
                people[ii]=x;
            }
            for(int worki=0;worki<=m;worki++){
                work[worki]=0;
            }
            for(int peoplei=0;peoplei<n;peoplei++){
                work[people[peoplei]]++;
                }
        }
        if(op==2){
            int x,w;
            cin>>x>>w;
            for(int ii=0;ii<n;ii++){
                if(people[ii]==x){
                    people[ii]=w;
                }
            }
            for(int worki=0;worki<=m;worki++){
                work[worki]=0;
            }
            for(int peoplei=0;peoplei<n;peoplei++){
                work[people[peoplei]]++;
                }
        }
        if(op==3){
            int x,y;
            cin>>x>>y;
            for(int ii=0;ii<n;ii++){
                if(people[ii]==x){
                    people[ii]=y;
                }
                else if(people[ii]==y){
                    people[ii]=x;
                }
            }
            for(int worki=0;worki<=m;worki++){
                work[worki]=0;
            }
            for(int peoplei=0;peoplei<n;peoplei++){
                work[people[peoplei]]++;
                }
        }
        if(op==4){
            int w;
            cin>>w;
            cout<<work[w]<<endl;
        }
        if(op==5){
            int max=0,maxpos=0;
            for(int ii=1;ii<=m;ii++){
                if(work[ii]==max&&ii<maxpos){
                    maxpos=ii;
                }
                if(work[ii]>max){
                    max=work[ii];
                    maxpos=ii;
                }
            }
            cout<<maxpos<<endl;
        }
    }
}









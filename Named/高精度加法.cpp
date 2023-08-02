#include<bits/stdc++.h>
#define MAXS 1000
using namespace std;
class mynum {
	public:
		int data[MAXS];
		mynum(char *s) {
			int ctr=MAXS-1;
			for(int i=0; i<MAXS; i++)
				data[i]=0;
			for(int i=strlen(s)-1; i>=0; i--)
				data[ctr--]=s[i]-'0';
		}
		void plus(mynum &tmp) {
			for(int i=MAXS-1; i>=0; i--) {
				data[i]=tmp.data[i]+data[i];
				if(data[i]>9) {
					data[i]=data[i]%10;
					if(i!=0)
						data[i-1]++;
				}
			}
		}
		void print() {
			int i;
			for(i=0;data[i]==0; i++);
			for(;i<MAXS; i++)
				cout<<data[i];
			cout<<endl;
		}
};
int main() {
	char a[MAXS],b[MAXS];
	cin>>a>>b;
	mynum as(a),bs(b);
	as.plus(bs);
	as.print();
	return 0;
}

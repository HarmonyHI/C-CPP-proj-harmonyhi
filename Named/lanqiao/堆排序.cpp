#include <algorithm>
#include <iostream>
using namespace std;
int a[]={46,79,56,38,40,84};
int main()
{
int i;
make_heap(a,a+sizeof(a)/sizeof(a[0]));
for(i=0;i<sizeof(a)/sizeof(a[0]);i++)
cout<<a[i]<<' ';
}

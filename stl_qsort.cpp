//STL库快排的使用方法



#include <iostream>
#include <algorithm>
using namespace std;
int cmp(const void * a,const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int a[10]={1,3,4,5,9,7,5,6,7,9};
	int i;
	qsort(a,10,sizeof(a[0]),cmp);
	for(i=0;i<10;i++)
		cout<<a[i]<<"  ";
	return 0;
}

//hdoj 1133
//问题转化成实现公式(m+n)!*(m-n+1)/(m+1)的编写
#include <iostream>
using namespace std;
const int MAX=210;
int a[MAX];
//求大数的阶乘
void fab(int zhi)
{
	int i=MAX-1;
    int arr=0;//进位
    int product;//乘积
    int j;
    int flag;
    for(flag=i;a[flag]!='0';flag--);
    for(j=i;j>flag+1;j--)
    {
        product=a[j]*zhi;
        a[j]=(product%10+arr)%10;
        arr=product/10;
    }
    product=a[j]*zhi;
    a[j]=(product%10+arr)%10;
    arr=product/10;
    if(arr>0)
        a[j-1]=arr;
}
void Data_Init(int m,int n)
{
    if(m<n)
    {
        cout<<0<<endl;
        exit(-1);
    }
    for(int i=0;i<210;i++)
        a[i]='0';
    if(n+m>=100)
    {
        a[MAX-1]=(n+m)%10;//个位
        a[MAX-2]=((n+m)/10)%10;//十位
        a[MAX-3]=(n+m)/100;//百位
    }
    if(n+m<10)
    {
        a[MAX-1]=n+m;
    }
    if(n+m>=10&&n+m<100)
    {
        a[MAX-1]=(n+m)%10;
        a[MAX-2]=((n+m)/10)%10;//十位
    }
}

int main()
{
    int m,n;
    cin>>m;
    cin>>n;
    Data_Init(m,n);
    for(int k=1;k<n+m;k++)
        fab(k);
    int i;
    for(i=MAX-1;a[i]!='0';i--);
    for(int j=i;j<MAX-1;j++)
        cout<<a[j+1];
	return 0;
}














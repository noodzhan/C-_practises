//大数求阶乘采用字符串转化的方法
#include <iostream>
#include <string.h>
#include <time.h>  //clock_t使用导入头文件。
using namespace std;
const int Max=40000;   //int 数组范围
int res[Max];
int main() {
    int n;
    clock_t start, finish;  //主要保存起始时间和终止时间
    double duration;  //耗时
    while(cin>>n && n>=0 && n<=10000){
        start=clock();
        memset(res,0,sizeof(res));   //初始化申请空间，并每位置0
        res[0]=1;  //0!=1
        for(int i=1;i<=n;i++)   //1~N
             //carry为进位，初始进位为0，个位没有进位
            for(int j=0,carry=0;j<Max;j++){
                res[j]=res[j]*i+carry;
                carry=res[j]/10;
                res[j]=res[j]%10; 
        }
        int i;
        for( i=Max-1;i>=0;i--) if(res[i]) break; 
        //从后往前(高位到低位)求出不为0的一项，即结果的最高位
        for(int j=i;j>=0;j--)   //高位到低位输出
            printf(j==0?"%d\n":"%d",res[j]);
        finish=clock();
        duration=(double)(finish-start)/CLOCKS_PER_SEC;//耗时
        cout<<n<<"! 耗时"<<duration<<"s"<<endl;
    }
    return 0;
}

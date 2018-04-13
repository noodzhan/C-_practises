#include<iostream>
using namespace std;
int main()
{
    int x,sum=0;
    //定义标号L1
L1: cout<<"x=";
    cin>>x;
    if (x==-1)
       goto L2;          //当用户输入-1时，转到L2语句处
    else
       sum+=x;
    goto L1;             //只要用户没有输入-1，则转到L1语句处，程序一直将用户的输入默默地累加到变量sum中。
    //定义标号L2
L2: cout<<"sum="<<sum<<endl;//一旦转到L2，将输出累计结果，程序运行结束。
    system("pause");
}

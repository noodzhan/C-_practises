//练习递归求最大值

#include <iostream>
using namespace std;
int get_max(int *a,int i){
    if(i==0)
        return *(a+i);
    else{
            int temp=get_max(a,i-1);
            return *(a+i)>temp?*(a+i):temp;
    }

}
int main(){
    int a[5]={1,2,3,10,4};
    cout<<get_max(a,4);
}

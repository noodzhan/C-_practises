#include <iostream>
#include <cmath>
using namespace std;




# if 0
//slow
int divide(int x,int y){
	int re=0;
	while(x>=y){
		x-=y;
		re++;
	}
	
	return re;

}
#endif 


int divide(int x,int y){
	int re=0;
	int count=0;
	
	int ant=0;
	
	//含有bug
	if(x<0){
		if(x==-2147483648)
			x=2147483647;
		x=-x;
		ant++;
	}
	if(y<0){
		y=-y;
		ant++;

	}
	int ly=y;

	//结束条件
	while(x>=ly){
		
		cout<<"x="<<x<<endl;
		if(x>=y){
			x-=y;
			re+=(1<<count);
			y=y<<1;
			cout<<"y="<<y<<endl;
			count++;

		}else{
			count=0;
			y=ly;
			cout<<"in"<<endl;
		}
		
	}
	
	return ant==1?-re:re;

}




int main(){


	cout<<divide(2,-1)<<endl;
	cout<<(1<<31)<<endl;

	return 0;

}

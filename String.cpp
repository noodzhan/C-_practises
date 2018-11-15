#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
typedef struct String
{
	char *ch;
	int length;
}HString;
void init_string(HString *,int length);
void StrAssign(HString *,char * );
int StringLength(HString );
void ClearString(HString * T);
bool SubString(HString T,HString *S ,int pos ,int length);
void Concat(HString *T,char *,char* );
int StrCampare(HString S,HString T);
int index(HString S,int pos, HString T);
int main(void)
{
	HString t;
	HString s1,s2,s3;//并没有给s1，s2，s3分配内存
	/* s1.ch=(char*)"a";
	s2.ch=(char*)"b"; */
	/* StrAssign(&t,(char*)"abcdefg");
	cout<<"字符串的长度："<<dec<<t.length<<endl;
	cout<<"字符串为："<<t.ch<<endl;
	cout<<"比较字符串长度 "<<StrCampare(s1,s2)<<endl;
	//ClearString(&t);
	SubString(t,&s3,2,5);
	cout<<"字符串S3："<<s3.ch<<"  字符串s3的长度："<<s3.length<<"  字符串t的长度："<< t.length<<endl; */
	/* Concat(&t,(char*)"abxbl",(char*)"vyigygy");
	cout<<t.length<<endl;
	printf("%s\n",t.ch); */
	s1.ch=(char*)"abcdefg";
	s1.length=7;
	s2.ch=(char*)"cde";
	s2.length=3;
	cout<<index(s2,1,s1);
	return 0;
}

void init_string(HString * T,int length)
{
	T->ch=(char*)malloc(sizeof(char)*length);
	if(NULL==T->ch)
	{
		cout<<"动态分配内存失败\n";
	    exit(-1);
	}
	T->length=length;
	return;
	
}

void StrAssign(HString * T,char * chars)
{
	int i;
	char *c;
	if(NULL!=T->ch)
		free(T->ch);
	for( i=0, c=chars;*c;i++,c++)//测量chars的长度，i的值就是长度
		if(!i)
		{
			T->ch=NULL;
			T->length=0;
		}
		if(!(T->ch=(char *)malloc(sizeof(char))))
		exit(-1);
	for(int j=0;j<i;j++)
		T->ch[j]=chars[j];
	T->length=i;
}



int StringLength(HString  T)
{
    return T.length;
}



void ClearString(HString * T)
{
	if(T->ch)
	{
		free(T->ch);
		T->ch=NULL;
	}
	T->length=0;
}

int StrCampare(HString S,HString T)
//若S>T，则返回>0；若S=T，则返回0；若S<T，则返回<0.
{
	int i;
	for( i=0;i<S.length&&i<T.length;i++)
		if(S.ch[i]!=T.ch[i])
			return S.ch[i]-T.ch[i];
		else
			return S.length-T.length;
}
bool SubString(HString T,HString *S,int pos ,int length)
//求子串S，取在T pos后面的长为length的子串。
{
	 if(pos<1||length<0)
		return false;
	else  
		if(S->ch)
			free(S->ch);
		if(!length)
		{
			S->ch=NULL;
			S->length=0;
		}
		S->ch=(char*)malloc(sizeof(char)*length);
		if(NULL==S->ch)
		{
			cout<<"动态分配内存失败\n";
			exit(-1);
		}
	    
		
		for (int j=0,i=pos-1;i<length+pos-1;i++,j++)
			S->ch[j]=T.ch[i]; 
		S->length=length;
		return true;
}



void Concat(HString *T,char* S1,char* S2)
// 此函数有问题不知道为什么输出合并的字符串总有
// 误差就是在s1与s2后面莫名的多些字母
{
	int S1_length,S2_length;
	char * s1;
	char *s2;
	if(T->ch)
		free(T->ch);
	for(S1_length=0,s1=S1;*s1;S1_length++,s1++);
	for(S2_length=0,s2=S2;*s2;S2_length++,s2++);
		T->ch=(char*)malloc(sizeof(char)*(S1_length+S2_length));
		if(NULL==T->ch)
		{
			cout<<"动态内存分配失败";
			exit(-1);
		}
		
		 for(int i=0;i<S1_length;i++)
			T->ch[i]=S1[i]; 
		for(int j=0,i=S1_length;i<S1_length+S2_length;i++,j++)
	    T->ch[i]=S2[j];
		
		T->length=S1_length+S2_length;
		return;
	
	
}


int index(HString S,int pos, HString T)
//在T里面找S，返回S的位置

{
	int i,j;
	i=pos-1;//t的下标
	j=0;//s的下标
	while(i<T.length&&j<S.length)
	{
		if(S.ch[j]==T.ch[i])
		{
			i++;j++;	
		}
		else
		{
			
	     i=i-j+1;
	     j=0;
		 
	    }
		   
	}
	if (j==S.length)
		return i-j+1;
	else
		return 0;
	
	
}


	
	
	
	


	























	

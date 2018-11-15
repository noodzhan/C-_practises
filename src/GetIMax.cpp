#include "GetIMax.h"

GetIMax::GetIMax()
{
    //ctor
}

GetIMax::~GetIMax()
{
    //dtor
}
int GetIMax::getimax(int *a,int i){

}
int GetIMax::getmax(int *a,int i){
    int tempmax=*a;
    for(int j=1;j<i;j++)
        if(*(a+j)>tempmax)
            tempmax=*(a+j);
    return tempmax;
}

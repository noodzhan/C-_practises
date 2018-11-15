#include "greed.h"
#include <cstdlib>
#include <iostream>
greed::greed()
{
    //ctor
    greed::requirement=20;

}

greed::~greed()
{
    //dtor
}
float greed::getmaxChoice(int type){
    int tempsize=greed::tsize;
    float eachprice[tempsize];
    for(int i=0;i<tempsize;i++){
        if(!greed::weight[i]){
             std::cout<<"weights have zero"<<std::endl;
             exit(0);
        }
        eachprice[i]=(float)greed::price[i]/(float)greed::weight[i];
    }
    #if 0
    std::cout<<" not sort eachprice"<<std::endl;
    for(int t=0;t<greed::tsize;t++){
        std::cout<<eachprice[t]<<" ";
    }
    #endif // 0
    int index[tempsize];
    for(int i=0;i<tempsize;i++)
        index[i]=i;

    //sort with index
    for(int i=0;i<tempsize;i++)
    for(int j=i;j<tempsize;j++){
        if(eachprice[i]<eachprice[j]){
            float temp=eachprice[i];
            eachprice[i]=eachprice[j];
            eachprice[j]=temp;
            temp=index[i];
            index[i]=index[j];
            index[j]=temp;
        }
    }
    #if 0
    std::cout<<std::endl<<"index"<<std::endl;

    for(int t=0;t<greed::tsize;t++){
        std::cout<<index[t]<<" ";
    }


    std::cout<<std::endl;
    std::cout<<"eachprice"<<std::endl;
    for(int t=0;t<greed::tsize;t++){
        std::cout<<eachprice[t]<<" ";
    }

    #endif // 0
    //greed
    int packweight=0;
    float allprice=0;
    int i=0;
    while(packweight<greed::requirement){
            //剩余多少空间或者是重量
        if((greed::requirement-packweight)<=weight[index[i]]){
            if(type==0){
                allprice+=(greed::requirement-packweight)*(price[index[i]]/weight[index[i]]);
                packweight=greed::requirement;
            }else{

                //处理01 背包问题
                if(i==greed::tsize-1)
                    return allprice;


            }
        }
        else{
            packweight+=greed::weight[index[i]];
            allprice+=greed::price[index[i]];

        }
        i++;
    }
    return allprice;

}

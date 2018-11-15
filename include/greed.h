#ifndef GREED_H
#define GREED_H

//贪心算法
class greed
{
    public:
        static const int tsize=10;
        greed();
        virtual ~greed();
        //解决的是一般的背包问题(包括01背包问题)
        //type==0 表示一般背包问题
        //type==1 表示01背包问题
        float getmaxChoice(int type);

    protected:

    private:
        int weight[tsize]={12,10,15,46,78,8,7,5,6,1};
        int price[tsize]={20,10,50,16,7,8,9,11,9,51};
        int requirement;
};

#endif // GREED_H

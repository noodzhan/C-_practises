#ifndef GREED_H
#define GREED_H

//̰���㷨
class greed
{
    public:
        static const int tsize=10;
        greed();
        virtual ~greed();
        //�������һ��ı�������(����01��������)
        //type==0 ��ʾһ�㱳������
        //type==1 ��ʾ01��������
        float getmaxChoice(int type);

    protected:

    private:
        int weight[tsize]={12,10,15,46,78,8,7,5,6,1};
        int price[tsize]={20,10,50,16,7,8,9,11,9,51};
        int requirement;
};

#endif // GREED_H

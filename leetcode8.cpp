class Solution {
public:
    static int t_pow(int n){
        int temp=1;
        if(n==0)
            return 1;
        for(int i=0;i<n;i++){
            temp*=10;
        }
        return temp;
    }
   static int stoken_to_int(int kind,list<char> chars){
        int re=0;
        char ch;
        const char t_MAX[10]={'2','1','4','7','4','8','3','6','4','7'};
        const char t_MIN[10]={'2','1','4','7','4','8','3','6','4','8'};
        int t_size=(int)chars.size();
        string stoken="";
        for(int i=0;i<t_size;i++){
            ch=chars.front();
            stoken+=ch;
            //cout<<"ch="<<ch-'0'<<endl;
            re+=(ch-'0')*t_pow(t_size-i-1);
            //cout<<"re="<<re<<endl;
            chars.pop_front();
        }
        int c_size=stoken.size();
       // cout<<"re="<<re<<endl;
        //cout<<"t_size"<<t_size<<endl;
        int k=0;
        while(stoken[k]=='0'){
            k++;
        }
        if(k==c_size)
            return 0;
        if(kind==1)
        {
            if(c_size-k>=10){
                int j=0;
                if(c_size-k==10)
                    for(j=0;stoken[j]<=t_MAX[j];j++){
                        if(stoken[j]<t_MAX[j])
                            return re;
                        else
                            if(j==9)
                                return re;
                    }
                        //return re;
                        

                return 2147483647;
            }

            return re;
        }else{

             if(c_size-k>=10){
                int j=0;
                if(c_size-k==10)
                    for(j=0;stoken[j]<=t_MIN[j]&&j<10;j++){
                         if(stoken[j]<t_MAX[j])
                            return -re;
                        else
                            if(j==9)
                                return -re;
                        
                    }
                return -2147483648;
            }

            return -re;
        }




    }
   static int myAtoi(string str) {
        int i=0;
        char ch=str[i];
        //int INT_MAX=2147483647;
        //int INT_MIN=-2147483648;
        list<char> chars;
        while(ch==' '){
            i++;
            ch=str[i];
        }
        if(ch=='+'){
            ch=str[++i];

            while(ch<='9'&&ch>='0'){
                chars.push_back(ch);
                i++;
                ch=str[i];

            }

            return stoken_to_int(1,chars);
        }else if(ch=='-'){
            ch=str[++i];

            while(ch<='9'&&ch>='0'){
                chars.push_back(ch);
                i++;
                ch=str[i];

            }

            return stoken_to_int(0,chars);

        }else if(ch<='9'&&ch>='0'){
            while(ch<='9'&&ch>='0'){
                chars.push_back(ch);
                i++;
                ch=str[i];

            }
            return stoken_to_int(1,chars);

        }else {
            return 0;
        }
    }
};

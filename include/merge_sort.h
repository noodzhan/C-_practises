#ifndef MERGE_SORT
#define MERGE_SORT
#include <vector>

class merge_sort{

private:
    static const int asize=10;
    static const int bsize=10;
    std::vector<int> m;
public:
    static void merge(int *a,int *b,int *c);
    static std::vector<int>  merge(std::vector<int> &a,std::vector<int> &b);

};



#endif // MERGE_SORT

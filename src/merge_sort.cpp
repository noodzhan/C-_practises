#include "merge_sort.h"

void merge_sort::merge(int *a,int *b,int *c){
	int i=0,j=0;
	int k=0;
	while(i<merge_sort::asize||j<merge_sort::bsize){

		if(*(a+i)<=*(b+j)){
			*(c+k)=*(a+i);
			i++;
			k++;
		}
		else{
			*(c+k)=*(b+j);
			j++;
			k++;
		}

	}
	while(i<merge_sort::asize){
		*(c+k)=*(a+i);
		i++;
		k++;
	}
	while(j<merge_sort::bsize){
		*(c+k)=*(b+j);
		j++;
		k++;
	}
}

std::vector<int>  merge_sort::merge(std::vector<int>&a,std::vector<int>&b){
    std::vector<int> re;
    int i=0;
    int j=0;
    while(i<a.size()||j<b.size()){
        if(a.at(i)<=b.at(j))
            re.push_back(a.at(i++));
        else
            re.push_back(b.at(j++));
    }
    while(i<a.size()){
        re.push_back(a.at(i++));
    }
    while(j<b.size()){
        re.push_back(b.at(j++));
    }
    return re;

}

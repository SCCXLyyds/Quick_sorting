#include <iostream>
using namespace std;
const int N=9;
void quick_sort(int a[],int begin,int end){
	if(begin>end){
		return;
	}
	int temp=a[begin];  //方便后面 temp和i=j时对应的值交换
	int i=begin;
	int j=end;
	while(i != j){
		while(a[j]>=temp && j>i){
			j--;
		}
		while(a[i]<=temp && j>i){
			i++;
		}
		if(j>i){
			int t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	} 
	a[begin]=a[i];
	a[i]=temp;
	quick_sort(a,begin,i-1);
	quick_sort(a,i+1,end); 
}
int main()
{   
	int a[9]={6,5,7,1,12,4,0,9,8};
	quick_sort(a,0,8);
	for(int i=0;i<9;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}

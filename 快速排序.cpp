//快速排序： 
//#include <iostream>
//using namespace std;
//const int N=1e6+10;
//int a[N],n,l,j;
//void quick_sort(int a[],int start,int end){
//	if(start>=end){
//		return;
//	} 
//	int temp=a[(start+end)/2];
//	l=start-1;j=end+1;
//	while(l<j){
//		do l++;while(a[l]<temp);
//		do j--;while(a[j]>temp);
//		if(l<j){
//			swap(a[l],a[j]);
//		}
//	}
//	quick_sort(a,start,j);
//	quick_sort(a,j+1,end);
//}
//int main()
//{
//	scanf("%d",&n);
//	for(int i=0;i<n;i++){
//		scanf("%d",&a[i]);
//	}
//	quick_sort(a,0,n-1);
//	for(int i=0;i<n;i++){
//		printf("%d ",a[i]);
//	}
//	return 0;
//}
//第 k 小的数 
#include <iostream>
using namespace std;
const int N=1e6+10;
int a[N],n,k;
int quick_find(int a[],int start,int end,int k) 
{
	if(start>=end) return a[end];
	int temp=a[(start+end)/2];
	int l=start-1,j=end+1;
	while(l<j){
		do l++;while(a[l]<temp);
		do j--;while(a[j]>temp);
		if(l<j) swap(a[l],a[j]);
	}
	if(k<=j+1-start) return quick_find(a,start,j,k);
	else return quick_find(a,j+1,end,k-j-1+start);
}
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<quick_find(a,0,n-1,k)<<endl;
	return 0;
}

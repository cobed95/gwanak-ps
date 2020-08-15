#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> stockPrices{10,7,5,8,11,9};
	int min=stockPrices[0],maxnow=stockPrices[0],maxprof=0;
	int vsize=stockPrices.size();
	for(int i=0;i<vsize;i++){
		if(min>stockPrices[i]){
			min=stockPrices[i];
		}
		else{
			if(stockPrices[i]-min>maxprof){
				maxprof=stockPrices[i]-min;
			}
		}
	}
	cout<<maxprof<<endl;
	return 0;
}

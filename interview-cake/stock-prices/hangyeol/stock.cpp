#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<map>
using namespace std;

int getMaxProfit(vector<int> sp,map<int, int> m){
	int max_profit = 0;
	auto it = m.begin();
	auto it2 = m.rbegin();
	if(it->second < it2->second) max_profit = it2->first - it->first;
	else{
	map<int, int> m1;
       	map<int, int> m2;
	for(int i = 0; i < m.size()-1;i++){	
		m1.insert(make_pair(it->first,it->second));
		m2.insert(make_pair(it2->first,it2->second));
	}	
	int maxm = getMaxProfit(sp, m2);
       	int minp = getMaxProfit(sp, m1);
	if(maxm >= minp) 	
		if(maxm > 0) max_profit = maxm;	
	else{
	if(minp > 0 ) max_profit = minp;
	}
	}
	return max_profit;	

}
bool verifyMaxProfit(vector<int> stockPrices, int maxProfit) {
    int max = 0;
    for (int i = 0; i < stockPrices.size(); i++) {
        for (int j = i + 1; j < stockPrices.size(); j++) {
            int profit = stockPrices[j] - stockPrices[i];
            if (max < profit) {
                max = profit;
            }
        }
    }
    return max == maxProfit;
}

int main()
{
map<int, int> m;
srand(static_cast<unsigned int>(time(0)));
vector<int> sp;
for(int i = 0 ; i<100;i++){
sp.push_back(rand());
}
for(int i = 0 ; i < sp.size();i++){
m.insert(make_pair(sp[i],i));
}
int answer = getMaxProfit(sp,m);
cout << answer<<endl ;
int real = verifyMaxProfit(sp,answer);
cout << real << endl;
}

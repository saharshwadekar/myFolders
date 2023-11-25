#include <iostream>
#include <vector>

using namespace std;

int main(){
  	int order , index;
  	cin >> order;
  	vector <bool> mp(order+1,false);
  	vector <int> p(order+1);
  	for(int i = 1 ; i <= order;i++){
      cin >> p[i];
  	}
  	cin >> index;
  	
  	int i = 1;
  	bool fl = false;
  	int count = 0;
  	while(1){
    	fl = false;
      	if(p[i] == order && i == index){
      		cout << count +1;
          	break;
        }
      	
      	if(!mp[i]){
        	if(p[i]<order)
              p[i]++;
          	else if(p[i] == order){
            	mp[i] = true;
              	i = 1;
              	fl = true;
              	count++;
            }
        }
      	if(!fl) i++;
      	if(i>order) i = 1;
    }
	return 0;
}
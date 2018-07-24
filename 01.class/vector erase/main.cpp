#include <iostream>
#include <vector> 
using namespace std;
  
int main(int argc, char** argv) {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	cout << v.size()<<endl;
	vector<int>::iterator it;  
 	int cnt = 0;
 	for(it=v.begin();it!=v.end();++it){  
 		cout <<"::::"<< *it << endl;
	}	
 	for(it=v.begin();it!=v.end();){  // erase 删除后不要++it，会跳过 
 		cout <<"-->"<< cnt <<endl;
 		cout << *it << endl;
 		if(cnt<3){  
  			v.erase(it);
		} else{
			++it;
		}
	 	cnt++;
	 	cout <<"-->>"<< cnt <<endl;
	}	
	cout << v.size()<<v[0]<<endl;
	return 0;	
}

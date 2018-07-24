#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <fstream>
using namespace std;

bool vec_cmp(pair<double,int> p1,  pair<double,int> p2){
	return p1.first > p2.first;
}

double calc_ent(vector<pair<double,int> > set_vec, double cut){
	// 1 统计数据 
	int s1=0,s2=0,c11=0,c12=0,c21=0,c22=0;
	for(int i = 0; i < set_vec.size(); ++i){
		if(set_vec[i].first<cut){
			s1++;
			if(set_vec[i].second==1)
				c12++;
			else
				c11++;
		}else{
			s2++;
			if(set_vec[i].second==1)
				c22++;
			else
				c21++;
		}
	}
	// 2 带入公式 
	double ent1,ent2;
	if(c11!=0 && c12!=0){
		ent1 = -1.0*c11/s1*log((1.0*c11)/s1)/log(2)-1.0*c12/s1*log((1.0*c12)/s1)/log(2); 
	}else if(c11!=0){
		ent1 = -1.0*c11/s1*log((1.0*c11)/s1)/log(2);
	}else{
		ent1 = -1.0*c12/s1*log((1.0*c12)/s1)/log(2);
	}
	 if(c21!=0 && c22!=0){
	 	ent2 = -1.0*c21/s2*log((1.0*c21)/s2)/log(2)-1.0*c22/s2*log((1.0*c22)/s2)/log(2); 
	 }else if(c21!=0){
	 	ent2 = -1.0*c21/s2*log((1.0*c21)/s2)/log(2); 
	 }else{
	 	ent2 = -1.0*c22/s2*log((1.0*c22)/s2)/log(2); 
	 }
	return (1.0*s1/(s1+s2))*ent1+(1.0*s2/(s1+s2))*ent2; 
}

bool calc_mdlpc(vector<pair<double,int> > set_vec, double cut, int ind){
	int s1=0,s2=0,c11=0,c12=0,c21=0,c22=0;
	set<int> cls1,cls2;
	for(int i = 0; i < set_vec.size(); ++i){
		if(i<=ind){
			s1++;
			cls1.insert(set_vec[i].second);
			if(set_vec[i].second==1)
				c12++;
			else
				c11++;
		}else{
			s2++;
			cls2.insert(set_vec[i].second);
			if(set_vec[i].second==1)
				c22++;
			else
				c21++;
		}
	}
	// 2 带入公式 
	double ent1,ent2;
	if(c11!=0 && c12!=0){
		ent1 = -1.0*c11/s1*log((1.0*c11)/s1)/log(2)-1.0*c12/s1*log((1.0*c12)/s1)/log(2); 
	}else if(c11!=0){
		ent1 = -1.0*c11/s1*log((1.0*c11)/s1)/log(2);
	}else{
		ent1 = -1.0*c12/s1*log((1.0*c12)/s1)/log(2);
	}
	 if(c21!=0 && c22!=0){
	 	ent2 = -1.0*c21/s2*log((1.0*c21)/s2)/log(2)-1.0*c22/s2*log((1.0*c22)/s2)/log(2); 
	 }else if(c21!=0){
	 	ent2 = -1.0*c21/s2*log((1.0*c21)/s2)/log(2); 
	 }else{
	 	ent2 = -1.0*c22/s2*log((1.0*c22)/s2)/log(2); 
	 }
	 	cout << "ent1>>"<<ent1 <<" ent2>>"<< ent2 <<endl;
	double ent  = -1.0*(c11+c21)/(s1+s2)*log(1.0*(c11+c21)/(s1+s2))/log(2)-1.0*(c12+c22)/(s1+s2)*log(1.0*(c11+c21)/(s1+s2))/log(2);
	cout << c11+c21 << "/" << s1+s2 << "：" << c12+c22 <<"/" << s1+s2 <<endl; 
	double delta = log(s1+s2-1)/log(2)/(s1+s2);
	cout <<"1>>>"<<delta << endl;
	delta+=(log(7)/log(2)-(2*ent-cls1.size()*ent1-cls2.size()*ent2))/(s1+s2);
	double gain= ent-calc_ent(set_vec,cut);
	cout <<"gain>>"<< gain << endl;
	cout <<"delta>>"<<delta << endl;
	return gain>delta;
}
void calc_mdlpc(vector<pair<double,int> > set_vec, double cut, int ind, vector<double> &res){
	int s1=0,s2=0,c11=0,c12=0,c21=0,c22=0;
	set<int> cls1,cls2;
	for(int i = 0; i < set_vec.size(); ++i){
		// 是否是  <= 
		if(i <= ind){
			s1++;
			cls1.insert(set_vec[i].second);
			if(set_vec[i].second==1)
				c12++;
			else
				c11++;
		}else{
			s2++;
			cls2.insert(set_vec[i].second);
			if(set_vec[i].second==1)
				c22++;
			else
				c21++;
		}
	}
	// 2 带入公式 
	double ent1,ent2;
	if(c11!=0 && c12!=0){
		ent1 = -1.0*c11/s1*log((1.0*c11)/s1)/log(2)-1.0*c12/s1*log((1.0*c12)/s1)/log(2); 
	}else if(c11!=0){
		ent1 = -1.0*c11/s1*log((1.0*c11)/s1)/log(2);
	}else if(c12!=0){
		ent1 = -1.0*c12/s1*log((1.0*c12)/s1)/log(2);
	}else{
		return;
	}
	 if(c21!=0 && c22!=0){
	 	ent2 = -1.0*c21/s2*log((1.0*c21)/s2)/log(2)-1.0*c22/s2*log((1.0*c22)/s2)/log(2); 
	 }else if(c21!=0){
	 	ent2 = -1.0*c21/s2*log((1.0*c21)/s2)/log(2); 
	 }else if(c22!=0){
	 	ent2 = -1.0*c22/s2*log((1.0*c22)/s2)/log(2); 
	 }else{
	 	return;
	 }
	cout << "ent1>>"<<ent1 <<" ent2>>"<< ent2 <<endl;
	double ent  = -1.0*(c11+c21)/(s1+s2)*log(1.0*(c11+c21)/(s1+s2))/log(2)-1.0*(c12+c22)/(s1+s2)*log(1.0*(c11+c21)/(s1+s2))/log(2);
	
	
	double delta = log(s1+s2-1)/log(2)/(s1+s2);
	cout <<"1>>>"<<delta << endl;
	delta+=(log(7)/log(2)-(2*ent-cls1.size()*ent1-cls2.size()*ent2))/(s1+s2);
	double gain= ent-calc_ent(set_vec,cut);
	cout<<"push__________1"<<endl;
	cout <<"gain>>"<< gain << endl;
	cout <<"delta>>"<<delta << endl;
	if(gain>delta){
		cout<<"push__________"<<endl;
		res.push_back(cut);
		vector<pair<double,int> > set_vec1(&set_vec[0],&set_vec[ind+1]);
		vector<pair<double,int> > set_vec2(&set_vec[ind+1], &set_vec[set_vec.size()]);
		/*
		cout <<"vec1>>>"<< set_vec1.size() << endl;
		cout << "------------"<<endl;
		for(int i=0; i< set_vec1.size(); ++i){
			cout << set_vec1[i].first << " "<< set_vec1[i].second<< endl;
		}
		cout << "------------"<<endl;
		cout <<"vec2>>>"<< set_vec2.size() << endl;
		cout << "------------"<<endl;
		for(int i=0; i< set_vec2.size(); ++i){
			cout << set_vec2[i].first << " " << set_vec2[i].second << endl;
		}
		cout << "------------"<<endl;
		*/
		double cut1,cut2;
		double min1=1000,min2=1000, ind1=-1,ind2=-1, mincut1,mincut2; 
		for(int i = 0; i < set_vec1.size()-1; ++i){
			// 2 取相邻两个属性值的中间值 为 候选切割点 
			cut1 = (set_vec1[i].first+set_vec1[i+1].first)/2;
			// 3 切割点 属性 过滤 
			if(set_vec1[i].second+set_vec1[i+1].second!=1)
				continue;
			// 4 计算 该切割 的 类信息熵 
			double entcut1 = calc_ent(set_vec1,cut1);
			if(entcut1<min1){
				min1 = entcut1;
				ind1 = i;
				mincut1 = cut1;
			}
		}
		for(int i = 0; i < set_vec2.size()-1; ++i){
			// 2 取相邻两个属性值的中间值 为 候选切割点 
			cut2 = (set_vec2[i].first+set_vec2[i+1].first)/2;
			// 3 切割点 属性 过滤 
			if(set_vec2[i].second+set_vec2[i+1].second!=1)
				continue;
			// 4 计算 该切割 的 类信息熵 
			double entcut2 = calc_ent(set_vec2,cut2);
			if(entcut2<min2){
				min2 = entcut2;
				ind2 = i;
				mincut2 = cut2;
			}
		}
		cout << "cut1>>> " << mincut1 <<" ind1>> " << ind1 << endl;
		cout << "cut2>>> " << mincut2 <<" ind2>> " << ind2 << endl;
		if(ind1!=-1)
			calc_mdlpc(set_vec1,mincut1,ind1,res);
		if(ind2!=-1)
			calc_mdlpc(set_vec2,mincut2,ind2,res);
	}else{
		return;
	}
}
int main(int argc, char** argv) {
	map<double,int> set_attr;
	
	// map 插入数据 
	/* 
	set_attr.insert(pair<double,int>(2.1,0));
	set_attr.insert(pair<double,int>(1.8,0));
	set_attr.insert(pair<double,int>(3.1,1));	
	set_attr.insert(pair<double,int>(2.9,1));
	set_attr.insert(pair<double,int>(2.3,0));
	set_attr.insert(pair<double,int>(3.3,1));
	set_attr.insert(pair<double,int>(3.6,1));
	set_attr.insert(pair<double,int>(3.4,1));
	set_attr.insert(pair<double,int>(3.5,1));	
	set_attr.insert(pair<double,int>(3.7,1));
		
	set_attr.insert(pair<double,int>(0.8,0));
	set_attr.insert(pair<double,int>(0.9,0));
	
	set_attr.insert(pair<double,int>(1.0,0));
	set_attr.insert(pair<double,int>(1.1,0));
	set_attr.insert(pair<double,int>(5.2,0));
	set_attr.insert(pair<double,int>(5.5,0));
	
	set_attr.insert(pair<double,int>(2.5,1));
	set_attr.insert(pair<double,int>(1.01,0));
	set_attr.insert(pair<double,int>(1.11,0));
	set_attr.insert(pair<double,int>(1.21,0));
	set_attr.insert(pair<double,int>(1.51,0));
	*/
	/*
	set_attr.insert(pair<double,int>(2.12,0));
	set_attr.insert(pair<double,int>(1.82,0));
	set_attr.insert(pair<double,int>(3.12,1));	
	set_attr.insert(pair<double,int>(2.92,1));
	set_attr.insert(pair<double,int>(2.32,0));
	set_attr.insert(pair<double,int>(3.32,1));
	set_attr.insert(pair<double,int>(3.62,1));
	set_attr.insert(pair<double,int>(3.42,1));
	set_attr.insert(pair<double,int>(3.52,1));	
	set_attr.insert(pair<double,int>(3.72,1));
		
	set_attr.insert(pair<double,int>(0.82,0));
	set_attr.insert(pair<double,int>(0.92,0));
	set_attr.insert(pair<double,int>(1.02,0));
	set_attr.insert(pair<double,int>(1.12,0));
	set_attr.insert(pair<double,int>(1.22,0));
	set_attr.insert(pair<double,int>(1.52,0));
	set_attr.insert(pair<double,int>(2.14,0));
	set_attr.insert(pair<double,int>(1.84,0));
	set_attr.insert(pair<double,int>(3.14,1));	
	set_attr.insert(pair<double,int>(2.94,1));
	set_attr.insert(pair<double,int>(2.34,0));
	set_attr.insert(pair<double,int>(3.34,1));
	set_attr.insert(pair<double,int>(3.64,1));
	set_attr.insert(pair<double,int>(3.44,1));
	set_attr.insert(pair<double,int>(3.54,1));	
	set_attr.insert(pair<double,int>(3.74,1));
		
	set_attr.insert(pair<double,int>(10.84,0));
	set_attr.insert(pair<double,int>(10.94,0));
	set_attr.insert(pair<double,int>(11.04,0));
	set_attr.insert(pair<double,int>(11.14,0));
	set_attr.insert(pair<double,int>(11.24,0));
	set_attr.insert(pair<double,int>(11.54,0));
		
	set_attr.insert(pair<double,int>(3.61,1));
	set_attr.insert(pair<double,int>(3.41,1));
	set_attr.insert(pair<double,int>(3.51,1));	
	set_attr.insert(pair<double,int>(3.71,1));	
	set_attr.insert(pair<double,int>(3.62,1));
	set_attr.insert(pair<double,int>(3.42,1));
	set_attr.insert(pair<double,int>(3.52,1));	
	set_attr.insert(pair<double,int>(3.72,1));	
	*/
	
//	*/
	ifstream fin("1.txt");
	double num;
	int flag;
	int n = 0;;
	int nd = 0;
	while(!fin.eof()){
		fin>>num>>flag;
		n++;
		nd = n%20;
		num = num + 0.000000001*20; 
		set_attr.insert(pair<double,int>(num,flag));
	}
	fin.close();
	//set_attr.insert(pair<double,int>(0.0150556,0));	
	cout<<set_attr.size()<<endl;
	// binary discrerization 计算
	// 1 map按值排序，此处多余 
	vector<pair<double,int> > set_vec(set_attr.begin(),set_attr.end());// 必须要有空格  > >
//	cout<<set_vec[0].first<<":"<<set_vec[0].second<<endl; 
	sort(set_vec.begin(),set_vec.end(),vec_cmp); 
//	cout<<set_vec[0].first<<":"<<set_vec[0].second<<endl;
//	cout<< set_vec.size()<<endl; 
	cout << "=============" << endl;
	for(int i=0;i<set_vec.size();++i){
		cout << set_vec[i].first <<"\t:\t"<< set_vec[i].second<<endl;
	}
	cout << "=============" << endl;
	double cut;
	double min=1000, ind, mincut; 
	for(int i = 0; i < set_vec.size()-1; ++i){
		// 2 取相邻两个属性值的中间值 为 候选切割点 
		cut = (set_vec[i].first+set_vec[i+1].first)/2;
		// 3 切割点 属性 过滤 
		if(set_vec[i].second+set_vec[i+1].second!=1)
			continue;
		// 4 计算 该切割 的 类信息熵 
		double entcut = calc_ent(set_vec,cut);
		if(entcut<min){
			min = entcut;
			ind = i;
			mincut = cut;
		}
		cout<<i<<"\t>>\t"<<entcut<<"\t"<<set_vec[i].second<<set_vec[i+1].second<<endl;
	}
	// 5 选出最小 切割 类信息熵 
	cout<< mincut << "\t:cut:\t" << ind << endl;
	
	cout << (calc_mdlpc(set_vec,mincut,ind)?"yes":"no")<<endl;
	vector<double> res;
	calc_mdlpc(set_vec,mincut,ind,res);
	cout << "res:" <<res.size()<< endl;
	for(int i= 0 ; i<res.size(); ++i){
		cout << res[i] << endl;
	}
	return 0;
}

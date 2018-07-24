#include <iostream>
#include <bitset>
#include <string>
#include <vector>
using namespace std;
int main(int argc, char** argv) {	
	
	//	string 中的  1 0 赋值给bit 
	string str("01001110001010");
	// 用字符串进行初始化 
	bitset<32> bv1(str);
	cout << "bv1 size >>　"<<sizeof(bv1) << endl;
	// cout number of 1 
	/// Returns the number of bits which are set.
	cout <<"number of 1 >>"<< bv1.count() <<endl;
	//@return  True if none of the bits are set.
	cout <<"all 0 ? >> "<< bv1.none() <<endl;
	cout <<"before flip >>" << bv1<<endl;
	bv1.flip();
	
	cout <<"after flip >> "<< bv1<<endl;
	//return  The value at @a pos.
	cout<<"test(2) >> "<<bv1.test(2)<<endl;
	bv1.reset();
	//return  The value at @a pos. 
	cout<<"test(2) after reset >> "<<bv1.test(2)<<endl;
	cout<<"bv1 after reset >> "<<bv1<<endl;

	return 0;
}

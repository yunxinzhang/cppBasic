#include <iostream>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int month = 10;
	int benjin = 100000;
	int yuebenxi = 10750;
	int delayMonth = 2; 
	char q;
	while( q != 'q'){
		std::cout << "借多少："<<std::endl;
		std::cin >> benjin ;
		std::cout << "每月还多少："<<std::endl;
		std::cin >> yuebenxi;
		std::cout <<"几个月不用还钱（第3月末开始还钱则此处为2）："<<std::endl;
		std::cin >> delayMonth ; 
		std::cout <<"还几个月（扣过几次款）："<<std::endl;
		std::cin >> month ; 
		
		for(int i = 0; i < 10000000; ++i){
			double x = 1.0*i/10000000;
			double y = 1.0*benjin/yuebenxi*pow(1+x,month+delayMonth);
			for(int j=0; j<month; ++j){
				y -= pow(1+x, j);
			}
			if(y > 0){
			//	std::cout << x <<"       \t"<< y<<std::endl;
				std::cout << "月息："<<std::endl; 
				std::cout << pow(1+x,12)-1 << std::endl;
				break;
			}		
		} 
		
		std::cout<< "\n按q退出，c继续" << std::endl; 
		std::cin >> q;
	}
	
	
	return 0;
}

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
		std::cout << "����٣�"<<std::endl;
		std::cin >> benjin ;
		std::cout << "ÿ�»����٣�"<<std::endl;
		std::cin >> yuebenxi;
		std::cout <<"�����²��û�Ǯ����3��ĩ��ʼ��Ǯ��˴�Ϊ2����"<<std::endl;
		std::cin >> delayMonth ; 
		std::cout <<"�������£��۹����ο��"<<std::endl;
		std::cin >> month ; 
		
		for(int i = 0; i < 10000000; ++i){
			double x = 1.0*i/10000000;
			double y = 1.0*benjin/yuebenxi*pow(1+x,month+delayMonth);
			for(int j=0; j<month; ++j){
				y -= pow(1+x, j);
			}
			if(y > 0){
			//	std::cout << x <<"       \t"<< y<<std::endl;
				std::cout << "��Ϣ��"<<std::endl; 
				std::cout << pow(1+x,12)-1 << std::endl;
				break;
			}		
		} 
		
		std::cout<< "\n��q�˳���c����" << std::endl; 
		std::cin >> q;
	}
	
	
	return 0;
}

#include <string>
#include "python.h"
using namespace std;
int main() {
	Py_Initialize();
	PyRun_SimpleString("import jieba");
	PyRun_SimpleString("print ('hello world!') ");	
	PyRun_SimpleString("print ('我是中国人。') ");
	PyRun_SimpleString("print (' '.join(jieba.cut('hello world'))) ");
	Py_Finalize();
	getchar();
}
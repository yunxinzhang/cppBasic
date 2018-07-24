#include <iostream>
#include <map>
#include <vector>

using namespace std;
template<typename T>
class graph{
	private:
		map<T,unsigned int> v2i;
		vector<T> i2v;
		unsigned int rank;
		unsigned int **matrix;	
		unsigned int capacity;
		bool directed;
	public:
		graph(unsigned int rank):capacity(capacity){
			matrix = new unsigned int *[capacity];
			for(unsigned int i=0; i<capacity;++i){
				matrix[i] = new unsigned int[capacity];
				for(unsigned int j=0; j<capacity; ++j){
					matrix[i][j]=0;
				}
			}
			rank = 0;
			cout << rank <<endl;
			directed = true;
		}
		~graph(){
			for(unsigned int i=0; i<capacity; ++i){
				delete[] matrix[i];
			} 
			delete[] matrix;
		}
		void print(){
			cout << rank <<"--"<<capacity<<endl;
//			for(unsigned int i=0;i<rank;++i){
//				for(unsigned int j=0; j<rank; ++j){
//					cout << matrix[i][j]<<'\t';
//				}
//				cout <<endl;
//			}
		}
		unsigned int get_index(T &v){
			return v2i.at(v);
		}
		bool add_vertice(T &v){
//			std::pair<std::map<T, unsigned int>::iterator, bool > v2i_ret;
//			v2i_ret;
//			cout << sizeof(v2i.insert(pair<T, unsigned int>(v, v2i.size()))<<endl;;
//			if(!v2i_ret.second){
//				return false;
//			}
//			i2v.push_back(v);
//			++rank; 
			return true;
		}
		bool add_edge(T &v1, T &v2){
			unsigned int row = get_index(v1);
			unsigned int col = get_index(v2);
			if(!directed){
				if(row != col){
					++matrix[row][col];
					++matrix[row][col];
				}else{
					++matrix[row][col];
				}
			}else{
				++matrix[row][col];
			} 
		
		} 
		unsigned int get_nout(T &v){
			unsigned int row = v2i.at(v);
			unsigned int res = 0;
			for(unsigned int i= 0; i< rank; ++i){
				if(matrix[row][i]!=0){
					++res;
				} 
			} 
			return res;
		}
		unsigned int get_nin(T &v){
			unsigned int col = v2i.at(v);
			unsigned int res = 0;
			for(unsigned int i= 0; i< rank; ++i){
				if(matrix[i][col]!=0){
					++res;
				} 
			} 
			return res;
		}
}; 
int main(int argc, char** argv) {
	graph<unsigned int> g(4);
//	unsigned int ff  = 0;
//	cout << ff << endl;
	g.print();
	cout << sizeof(NULL);
//	std::pair<std::map<int, unsigned int>::iterator, bool > v2i_ret;
	return 0;
}

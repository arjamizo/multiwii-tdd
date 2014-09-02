#include <stdint.h>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <sstream>
#include <set>
#include <list>
#include <vector>

using namespace std;

class Serializable {
	public:
	virtual operator std::string()=0;
};
std::set<Serializable*> vars;
template <typename STR, typename T> //str template allows accepting both std::string and char[]
class EvaluableExpression : public Serializable {
	string variableName;
	T &ref;
	public:
	EvaluableExpression(STR str, T &ref):ref(ref) {
		variableName=str;
		vars.insert(this);
	}
	operator std::string() {
		stringstream ss;
		ss<<variableName<<" "<<ref;
		return ss.str();
	}
	~EvaluableExpression() {
		vars.erase(this);
	}
};

template <typename STR, typename T, typename SIZE> //str template allows accepting both std::string and char[]
class EvaluableExpressionArray : public Serializable {
	string variableName;
	SIZE &size;
	T &ref;
	public:
	EvaluableExpressionArray(STR str, T &ref, SIZE &size):size(size),ref(ref) {
		variableName=str;
		vars.insert(this);
	}
	//TODO: allow accepting sixe (num parameter) as a pointer to empty-argument list, so expression like EvaluableArrayExpression("MOTORS", vectorOfMotors, vectorOfMotors.size) is acceptable
	operator std::string() {
		stringstream ss;
		ss<<variableName;
		for(int i=0; i<size; i++) ss<<" "<<ref[i];
		return ss.str();
	}

	~EvaluableExpressionArray() {
		vars.erase(this);
	}
};


template <typename STR, typename T>
void ev(STR str, T (&ref)) {
	cout<<string(* new EvaluableExpression<STR, T>(str, ref))<<endl;
	//cout<<str<<endl;
}
template <typename STR, typename T, typename SIZE>
void ev(STR str, T (&ref), SIZE &num) {
	cout<<string(* new EvaluableExpressionArray<STR, T, SIZE>(str, ref, num))<<endl;
	//cout<<str<<endl;
}
template <typename STR, typename T, typename SIZE>
void ev(STR str, T *(ref), const SIZE &num) {
//	cout<<EvaluableExpressionArray<STR, T, SIZE>(str, ref, num)<<endl;
	cout<<str<<endl;
}

//void evarray(char str[]) {
	//cout<<EvaluableExpressionArray<char[], uint16_t, int>(str, ref, num)<<endl;
//}

void *printEach5Seconds(void *cout_ptr) {
    #if not defined (PTHREADS)
    int repeat=0;
	#else
    int repeat=1;
	#endif
	do {
		//std::ostream &cout=*(std::ostream*)cout_ptr;
		cout<<"vars.size"<<vars.size()<<endl;
		vector<Serializable*> varss(vars.begin(), vars.end());
		for(int i=0; i<varss.size(); ++i) {
			cout<<"serializing ";
			cout<<std::string(*varss[i])<<endl;
		}
		sleep(1);
	} while(repeat);
	return 0;
}

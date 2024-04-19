#include <iostream>
using namespace std;

class SWE{
	public:
		void display(){
			cout << "I am a software student" <<endl;
		}
};

class NWS{
	public:
		void display(){
			cout << "I am a network and security student" <<endl;
		}
};

class CSN{
	public:
		void display(){
			cout << "I am a computer network and security student" <<endl;
		}
};

class ICT: public SWE, public NWS, public CSN{
	public: 
		void displayICT(){
			cout << "I belong to all categories" <<endl;
		}
};


int main(){
// instance of the SWE class 
	SWE sweobj;
	sweobj.display();

// instance of the NWS class 
	NWS nwsobj;
	nwsobj.display();
	
// instance of the CSN 
	CSN cnsobj;
	cnsobj.display();
	
	
//  instance of the ICT class 
	ICT ictobj;
	ictobj.displayICT();
	
//	using the scope resolution operator
	ictobj.SWE::display();
	
}
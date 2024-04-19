#include <iostream>
#include <cmath>
using namespace std;


class Circle{
	private: 
		double radius = 1.0;
		string color = "red";
		
	
	public: 
		Circle(){
			
		}
		
		Circle(double r){
			radius = r;
		}
		
		Circle(double r, string c){
			radius = r;
			color = c;
		}
		double getRadius(){
			return radius;
		}
		
		string getColor(){
			return color;
		}
		
		double getArea(){
			return 3.14 * pow(radius, 2);
		}
};




int main(){
	Circle c1(2.0,"blue");
	
//	c1 instance
	cout << "C1 instance" << endl;
	cout << c1.getColor() << endl;
	cout << c1.getRadius() << endl;
	cout << c1.getArea() << endl;
	

// c2 instance 
	
	Circle c2(2.0, "red");
	cout << endl << "C2 Instance" <<endl;
	cout << c2.getColor() <<endl; 
	cout << c2.getRadius() <<endl;
	cout << c2.getArea() <<endl;
	

// c3 instance 
	
	Circle c3(1.0, "red");
	cout <<endl << "C3 instance" <<endl;
	cout <<c3.getColor() <<endl;
	cout <<c3.getRadius() <<endl;
	cout <<c3.getArea() <<endl;

	
}
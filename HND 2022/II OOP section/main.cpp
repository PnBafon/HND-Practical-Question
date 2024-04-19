#include <iostream>
using namespace std;

class BankAccount{
	private: 
		int amount = 0;
		
	public: 
		string name;
		string pin;
	
//		amount getter
		int getAmmount(){
			return amount;
		}
			
//		amount setter
		void setAmmount(int amt){
			amount += amt;
		}
		
//		abstract methods 
		
		virtual deposit(string name1, string pin1, int amt1) = 0;
		
		virtual withdrawal(string name2, string pin2, int amt2) = 0;
		
		virtual DisplayInfo(string name3, string pin3) = 0; 
		
		virtual Change_pin(string name, string oldpin, string newpin) = 0;
		
};


class MyBankAccount : public BankAccount{
	public: 
		MyBankAccount(){
			name = "Ngong";
			pin = "p";
			setAmmount(0);
		}
		
		MyBankAccount(string name0, string pin0){
			name=name0;
			pin= pin0;
			setAmmount(0);
		}
		
//		Deposit method
		deposit(string name1, string pin1, int amt1){
			
			if (name1== name && pin1 == pin){
				
				setAmmount(amt1);
				
			} else {
				cout << "User name and pin code do not march" <<endl;
			}
			
//			return ; 
		}
		
//		Widthdrawal method
		withdrawal(string name2, string pin2, int amt2){
			if(name == name2 && pin2 == pin2){
				setAmmount(-amt2);
			} else {
				cout << "User name and pin code do not march" <<endl;
			}
			
//			return;
		}
		
//		displayinfo method
		DisplayInfo(string name3, string pin3){
			if (name==name3 && pin==pin3){
				cout <<endl << "Name: " << name <<endl;
				cout << "Account Balance: " << getAmmount() <<endl;
				
			}else {
				cout << "User name and pin code do not march" <<endl;
			}
		}
		
//		change pin method
		Change_pin(string name4, string oldpin, string newpin){
			if (name==name4 && pin==oldpin){
				pin = newpin;
			} else {
				cout << "User name and pin code do not march" <<endl;
			}
		}
};


void getUserDetails();
void displayMenu();
string name, pin, newpin;
int choice, amt; 
bool continue_iteration = true;
	
int main(){

	getUserDetails();
	
//	creating an object 
	MyBankAccount acc1(name,pin);
	
	while (continue_iteration){
//		Displaying the Menu and Getting the User's choice
		displayMenu();
		cin >> choice;
		
//		working with the User choice
		switch (choice){
			case 1:
				getUserDetails();
				cout << "Enter amount you want to deposit: ";
				cin >> amt;
				acc1.deposit(name, pin, amt);
				break;
			case 2: 
				getUserDetails();
				cout << "Enter amount you want to withdraw: ";
				cin >> amt;
				acc1.withdrawal(name, pin, amt);
				break;
			case 3:
				
				getUserDetails();
				acc1.DisplayInfo(name,pin);
				break;
			case 4: 
				
				getUserDetails();
				cout << "Enter new pin: ";
				cin >> newpin;
				acc1.Change_pin(name, pin, newpin);
				break;
			case 0:
				continue_iteration = false;
				break;
			default: 
				cout << "Sorry invalid choice" <<endl; 
				break;
		}
	}
	
}
	//  getting user details
void getUserDetails(){
		
		cout << "Enter your name: ";
		cin >> name; 
		cout << "Enter you pin: ";
		cin >> pin; 
	}

// Display Menu	
void displayMenu(){
		cout << "----------MENU-----------" <<endl;
		cout << "1 - Deposit" << endl << "2 - Withdrawal" << endl << "3 - Account Details" <<endl 
			 << "4 - Change Pin" << endl << "0 Quit" <<endl <<"Enter Choice: ";
	}



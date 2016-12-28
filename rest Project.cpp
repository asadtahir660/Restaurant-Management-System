#include<iostream>
#include<string.h>
using namespace std;



class Sales{
	private:
		
		string ID;
		string cash;
		string employeeID;
		
	public:
		void addSales(int x, string ID){
			//write this in database
		}
			
		void showSales (string ID){
			//open database
			//serch the given emplooe ID
			// cout all the result
		}
			
		void showSales (){
			//open data base
			//cout every theing
		}
			
};

class Employee {
	private:
	
		string employeeID;	
		string name;
		string contact;
		string address;
		string shift;
		
	public:
						
		void editOrder (string ID){
			//open database conction 
			//serch database for given string
			//bring back record and save in class variables
			//make changes
			// write to file
				
			
		}
		void takeOrder(){
					
		string orderID;
		int tableNumber;
		string itemID[20];
		int i=0;	
	
		cout << "Order ID : "; cin>> orderID;
		cout << "Your ID : ";	cin >> employeeID;
		cout << "Enter TAble No : " ; cin >> tableNumber;
		cout << "Enter Order(Item ID),Enter End to save : ";
		
		while (itemID[i]!= "End"){
			cin>> itemID[i];
			i++;
			}
		//write All this to file 
		
		}
};

class Order : public Employee {
	private:
		
		string ID;
		int tableNumber;
		string itemID[20];
		int bill;
		bool done;
		int i=0;	
	
	public:
		
		void finalize(string ID){
			Sales newSale;
			int temp = getBill(ID);
			newSale.addSales(temp, ID);
	     
		}
		int getBill (string ID){
			int sum=0;
			//serch the order ID 
			//call the Item list 
			//In a For loop Take each item id call the menu class and get the price
			//add the prices
			return sum;
		}
		
};

class Menu{
	private:
		
		string itemID;
		string itemName;
		int price;
		
		public:
			void showMenu ();
			
			void addItem (string, string, int){
				
			}
			
			void editPrice (string, int){
				
			}
			
			void getPrice (string){
				
			}
			
};

class Reservation : public Employee{
	private: 
	
		string ID;
		string date;
		string timeStart;
		string timeEnd;
		int table_number;
	
	
	public:
		
		void makeReservation (){
			
		}
		void finalizeReservation (){
			
		}
		
		bool available (string){
						
		}
		
};

class Owner{
	private: 
		string ID="Asad Tahir";
		string pasward = "asad1234";
		string employeeID;	
		string name;
		string contact;
		string address;
		string shift;
	
	public:
		bool logIn(string a, string b){
			if (a==ID && b==pasward){
				return true;
				
			}else
				return false;
		}
		void addEmployee(){
			cout << "Enter Employee ID : ";cin>>employeeID;
			cout << "\nEnter Employee Name : ";cin>>name;
			cout << "\nEnter Employee Contact : ";cin>>contact;
			cout << "\nEnter Employee Address : ";cin>>address;
			cout << "\nEnter Employee Shift : ";cin>>shift;
			// write All to database
		}
		void fireEployee(){
			cout << " Enter Employee ID : ";cin>>employeeID;
			//serch in database delet All record about employee 
			
		}
		void viewSales (){
			// open data base Print everythink 
		}
	
};
int main(){
	int Choice;
	Order employee; Owner login;
	string order;
	cout << "Restorent Management System v1.0";
	cout << " Press 1 to place order : " ;
	cout << " Press 2 to change order : ";
	cout << " Press 3 to finsh order : ";
	cout << " Press 4 to Login : ";
	cin >> Choice;
	switch (Choice){
		case 1:
			employee.takeOrder();
			break;
		case 2:
			cout << "Enter Order ID : ";cin >> order;
			employee.editOrder(order);
			break;
		case 3:
			cout << "Enter the Order ID : ";cin >> order;
			
			employee.finalize(order);
			break;
		case 4:
			string pasw;
			cout << "Enter ID : ";cin >> order;
			cout << "Enter pasward : ";cin >> pasw; 
			if(login.logIn(order , pasw))
			{
				cout << "Enter 1 to Add Employee : "<<endl;
				cout << "Enter 2 to remove Employee : "<<endl;
				cout << "Enter 3 to view Sales : "<<endl;
				cin>>Choice;
				
				switch(Choice){
					case 1:
						login.addEmployee();
						break;
					case 2:
						login.fireEployee();
						break;
					case 3:
						login.viewSales();
						break;
				}
			}
			else
			{
				cout << "Wrong Credentials!"<<endl;
			}
			break;
	}
	
}

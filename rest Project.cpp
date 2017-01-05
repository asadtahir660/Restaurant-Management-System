#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
using namespace std;



class Sales{
	private:
		ofstream myfile;
		string ID;
		string cash;
		string employeeID;

	public:
		void addSales(int x, string eID, string oID){

			myfile.open ("salesRecord.bin", ios::out | ios::app | ios::binary);
			if (myfile.is_open()){
                myfile << eID;
                myfile << "\n";
                myfile << oID;
                myfile << "\n";
                myfile << x;
                myfile << "\n";
                myfile << "end";
                myfile.close();
          }
            else cout << "Unable to open file";
		}

		void showSales (string eID){
			ifstream myinputfile ("salesRecord.bin");
            if (myinputfile.is_open()){

                string line;
                cout << "Employee ID \t Order ID \t Sale (In Rupees)\n\n";
                while ( getline (myinputfile,line) )
                {
                  if(line == eID)
                  {
                        cout << line << "\t ";
                        getline (myinputfile,line);
                        cout << line << "\t ";
                        getline (myinputfile,line);
                        cout << line << "\n\n ";
                  }
                  else
                  {
                      getline (myinputfile,line);
                      getline (myinputfile,line);
                      getline (myinputfile,line);
                  }

                }
                myinputfile.close();
            }

            else cout << "Unable to open file";
		}

		void showSales (){

			ifstream myinputfile ("salesRecord.bin");
            if (myinputfile.is_open()){

                string line;
                cout << "Employee ID \t Order ID \t Sale (In Rupees)\n\n";
                while ( getline (myinputfile,line) )
                {
                  if(line != "end")
                  {
                        cout << line << "\t ";
                        getline (myinputfile,line);
                        cout << line << "\t ";;
                        getline (myinputfile,line);
                        cout << line << "\n\n ";
                  }

                }
                myinputfile.close();
            }

            else cout << "Unable to open file";
		}

};

class Employee {
	public:

		string employeeID;
		string name;
		string contact;
		string address;
		string shift;

};

class Order : public Employee {
	private:

		string order[50][24];
		int bill;
		bool done;
		int i;
		int ordernumber=0;

	public:

        void takeOrder(){
            i=3;
            ordernumber++;

            cout << "\n Enter Order ID";
            cin >> order[ordernumber][0];
            cout << "\nEnter your ID ";
            cin >> order[ordernumber][1];

            cout << "\n Enter Table Number";
            cin >> order[ordernumber][2];
            cout << "\nPlace Order (enter Item IDs only)\t\t Type 'end' to finish";

            do{
                cin >> order[ordernumber][i];
                i++;
            }while(order[ordernumber][i] != "end");
        }

        void editOrder(string oID){
            int j=0, k=3, l=1;
            int temp;
            while(true)
            {
                if(order[j][0] == oID)
                {
                    cout << "Enter Item number to change.\n\n";
                    cout << "Current order: \n";
                    while(order[j][k] != "end")
                    {
                        cout << l << "    " << order[j][k] << "\n";
                        l++;
                        k++;
                    }
                    cin>>temp;
                    cout << "Enter 'X to just remove item\n";
                    cout << "Enter new item:  ";
                    cin>> order[j][temp];

                    break;
                }
                j++;
            }
        }

		void finalize(string oID){
			Sales newSale;
			int temp = getBill(oID);
			cout << "Enter your ID: ";
			cin >> employeeID;
			newSale.addSales(temp, oID, employeeID);

		}
		int getBill (string ID){
			int sum=0;

			return sum;
		}

};

class Menu{
	private:

		string itemID;
		string itemName;
		string price;
        string done;
        ofstream myfile;

		public:
			void showMenu (){
                  string line;
                  ifstream myinputfile ("menu.bin");
                  if (myinputfile.is_open())
                  {
                    cout << "Code\tName\tPrice (per serving)";
                    while ( getline (myinputfile,line) )
                    {
                      cout << line << "\t";
                      getline (myinputfile,line);
                      cout << line << "\t";
                      getline (myinputfile,line);
                      cout << line << "\t";
                      getline (myinputfile,line);
                      cout << endl;
                    }
                    myinputfile.close();
                  }

                  else cout << "Unable to open file";
			}

			void addItem (string i, string n, string p){
                sigh:
                cout << "\nEnter product code: ";
                cin >> itemID;
                cout << "\nEnter product name: ";
                cin >> itemName;
                cout << "\n Enter product cost: ";
                cin >> price;
                cout << "\n\nAdd item to menu? (Y / N)  ";
                cin >> done;

                if(done == "N" || done == "n"){
                        system("cls");
                        goto sigh;
                }
                else{

                    myfile.open ("menu.bin", ios::out | ios::app | ios::binary);

                  if (myfile.is_open())
                  {
                    myfile << itemID;
                    myfile << "\n"; // har entry ko seperate krne k lye
                    myfile << itemName;
                    myfile << "\n";
                    myfile << price;
                    myfile << "\n";
                    myfile.close();
                  }
                  else cout << "Could not add item to menu...Unable to open file";
                }
			}

			int getPrice (string code){
                    int price;

                  string line;
                  ifstream myinputfile ("menu.bin");
                  if (myinputfile.is_open())
                  {

                    while ( getline (myinputfile,line) )
                    {
                      if(line == code){
                        getline (myinputfile,line);
                        getline (myinputfile,line);
                        price = atoi(line.c_str());
                        return price;
                      }
                    }
                    myinputfile.close();
                  }

                  else{
                    cout << "Unable to fetch item price";
                    return 666;
                  }



			}

};

class Reservation : public Employee{
	private:
        ofstream myfile;
		string ID;
		string date;
		string name;
		string timeStart;
		string table_number;


	public:

		void makeReservation (){
            cout << "Enter your ID: ";
            cin >> ID;
            cout << "Enter Date: ";
            cin >> date;
            cout << "Enter Time: ";
            cin >> timeStart;
            cout << "Enter Table Number: ";
            cin >> table_number;
            cout << "Enter Customer Name: ";
            cin >> name;

            if(available(date,timeStart, table_number))
            {
                 myfile.open ("reservations.bin", ios::out | ios::app | ios::binary);
                if (myfile.is_open()){
                    myfile << name;
                    myfile << "\n";
                    myfile << date;
                    myfile << "\n";
                    myfile << timeStart;
                    myfile << "\n";
                    myfile << table_number;
                    myfile << "\n";
                    myfile << ID;
                    myfile << "\n";
                    myfile.close();
                }
                else cout << "Unable to open file";
            }
            else
                cout << "Reservation not possible.\t";
		}

		bool available (string D, string T, string TN){
            string line;
            ifstream myinputfile ("example.bin");
            if (myinputfile.is_open())
            {
                while ( getline (myinputfile,line) )
                {
                  getline (myinputfile,line);
                  if(line == D)
                  {
                      getline (myinputfile,line);
                      if(line == T)
                      {
                          getline (myinputfile,line);
                          if(line == TN)
                          {
                              return false;
                          }
                          else
                            return true;
                      }
                  }
                }
                myinputfile.close();
            }
            else
            {
                cout << "Unable to open file";
                return false;
            }
		}

};

class Owner : public Menu, public Sales{
	private:
		string ID= "Asad Tahir";
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
			// serch in database delet All record about employee

		}

};

int main(){
	int Choice;
	Order employee; Owner login; Reservation make;
	string order;
	again:
	cout << "\t\t====================================\n";
	cout << "\t\t  Restaurant Management System v1.0\n";
	cout << "\t\t====================================\n";
	cout << "Select an option:\n";
	cout << " 1 Place Order\n" ;
	cout << " 2 Change Order\n";
	cout << " 3 Finish Order\n";
	cout << " 4 Make Reservation\n";
	cout << " 5 Login\n";
	cout << " 6 Exit\n\n";
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
                cout << "Note: Reservations can be made for only the current month.\n\n";
                make.makeReservation();
        case 5:
            {
                string pasw;
                cout << "Enter ID : ";cin >> order;
                cout << "Enter password : ";cin >> pasw;
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
                            string opt;
                            cout << "Enter Employee ID to view sales or Enter 'A' to view all sales:  ";
                            cin >> opt;
                            if(opt == "A" || opt == "a")
                            {
                                    login.showSales();
                            }
                            else
                                login.showSales(opt);

                            break;
                    }
                }
                else
                {
                    cout << "Wrong Credentials!"<<endl;
                }
                break;
		    }

        default:
                cout<< "\a";
        }
    system("cls");
    goto again;
}

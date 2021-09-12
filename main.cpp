
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;



struct myEmployee{
  int employeeID;
  string employeeName;
};
struct myCustomer{
   int customerID;
   string customerName;
   float balance;
};

//create array to hold the structures
myEmployee empArray[20];//maximum 20 employees
myCustomer cusArray[50];//maximum 50 customers



int searchEmployees(int id , int NoOfEmployees){
	int count;
	for (count = 0 ; count < NoOfEmployees; count++){
		if(empArray[count].employeeID == id){
			return 1;//basically employee has been found
		}
		else{
			return 0; // has not been found
		}
	}
}

int searchCustomers(int id, int NoOfCustomers){
	int count;
	for (count = 0 ; count < NoOfCustomers; count++){
		if(cusArray[count].customerID == id){
			return 1;//basically customer has been found
		}
		else{
			return 0; // has not been found
		}
	}
}

void displayEmployeeArray(){//this is just to check if data has been entered correctly. Used in debugging
    for(int i=0;i<9;i++){
        cout<<"Details of employee #"<<(i+1)<<" are:\n";
        cout<<" ID: "<<empArray[i].employeeID<<"\n" ;
        cout<<" Name: "<<empArray[i].employeeName<<"\n";
    }
}

void displayCustomerArray(){//this is just to check if data has been entered correctly. Used in debugging
    for(int i=0;i<10;i++){
        cout<<"Details of customer #"<<(i+1)<<" are:\n";
        cout<<" ID: "<<cusArray[i].customerID<<"\n" ;
        cout<<" Name: "<<cusArray[i].customerName<<"\n";
        cout<<" Balance: "<<cusArray[i].balance<<"\n";
    }
}

myEmployee  getEmployee(int id){
	int count;
	for (count = 0 ; count < 9; count++){
		if(empArray[count].employeeID == id){
			return empArray[count];//basically customer has been found
		}

	}
}
myCustomer getCustomer(int id){
	int count;
	for (count = 0 ; count < 10; count++){
		if(cusArray[count].customerID == id){
			return cusArray[count];//basically customer has been found
		}

	}
}



main(){
int i, j, tChecker=0, customerCount=0, employeeCount=0, temp;
float bal;
char choice;
myEmployee currentEmployee;
myCustomer currentCustomer;
string line, word;
ifstream in ("input.txt");

//start getting inputs
while(getline(in, line))
{
	stringstream ss(line);
	word="";
	switch(line.at(0)) { //check the first letter of each line
		case 'e' :
					if (tChecker) {
						cout<<"Transactions already started!\n";
					}
					else {
						if (employeeCount<20) {
							ss>>choice>>temp>>word;
							if (word.length() <= 15 && searchEmployees(temp, employeeCount) ==0) {
								empArray[employeeCount].employeeName= word;
								empArray[employeeCount].employeeID= temp;
								employeeCount++;
							//	cout<<"Employee "<< word <<" logged in\n";
							}
							else cout<<"Name limit is 15\n";
						}
						else cout<<"Employee limit is 20\n";
					}
			break;
		case 'c' :
					if (tChecker) {
						cout<<"Transactions already started!\n";
					}
					else {
						if (customerCount<80) {
							ss>>choice>>temp>>word>>bal;

							if (word.length() <= 15 && searchCustomers(temp, customerCount) ==0) {
								cusArray[customerCount].customerName=word;
								cusArray[customerCount].customerID= temp;
								cusArray[customerCount].balance= bal;
								customerCount++;
							//	cout<<"Customer "<<word<<" logged in\n";
							} else cout<<"Name limit is 15\n";
						}
						else cout<<"Customer limit is 80";
					}
			break;
		case 't' :
					if (!tChecker) {
						cout<<"Transactions starts now!\n";
						tChecker=1;
					}
					ss>>choice>>temp>>j>>choice>>bal;
					if(choice=='w') bal*=-1;//make balance change negative if it is withdrawal
					currentEmployee = getEmployee(j);
					currentCustomer = getCustomer(temp);
					currentCustomer.balance += bal;


                    cout<<currentCustomer.customerName<<" ";
					cout<<currentEmployee.employeeName<<" ";
					printf("%0.2f %0.2f\n",bal, currentCustomer.balance);
			break;
		}
}//end while


//displayEmployeeArray();
//displayCustomerArray();

}//end main

#include <iostream>
using namespace std;
class Employee{
    private:
    // static int counter;
    protected:
        static int counter;
        string name;
        double salary;
        
    public:
    Employee(string n, double s){
        name= n;
        salary= s;
        counter++;
    }
    virtual void displayInfo(){
        cout<<"Name: "<< name<<", Salary: "<<salary<<endl;
    }
    static void showTotalEmployees(){
        cout<<"Total Employees Created: "<<counter<<endl;
    }
    virtual ~Employee(){
    };

};

int Employee::counter=0;

class Staff: public Employee{
    private: 
    string department;
    public:
    Staff(string d, string n, double s): Employee(n, s){
        department= d;
    }
    virtual void displayInfo() override{
        cout<<"Name: "<<name<<" ("<<department<<"), Salary: "<<salary<<endl;
    }

};

class Faculty: public Employee{
    private:
    string department;
    public:
    Faculty(string d, string n, double s): Employee(n,s){
        department=d;
    }

    virtual void displayInfo() override{
        cout<<"Name: "<< name<<" ("<<department<<"), Salary: "<<salary<<endl;
    }

};

int main() {
    int num;
    string d;
    string n;
    double s;
    cout<<"Enter the number of Employees: ";
    cin>>num;
    Employee* emps[num];
    for(int i=0; i<num; i++){
        cin>>d;
        cin>>n;
        cin>>s;
        if(d=="Staff"){
            emps[i]= new Staff(d, n, s);
        }else if(d=="Faculty"){
            emps[i]= new Faculty(d, n, s);
        }
    }

    for(int i=0; i<num; i++){
        emps[i]->displayInfo();
    }
    Employee::showTotalEmployees();
    return 0;
}
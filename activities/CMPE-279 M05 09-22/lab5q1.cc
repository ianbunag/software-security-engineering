#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <unordered_map>
using namespace std;

unordered_map<string, void*> all_employees;

class Employee {
protected:
    char name[32];
    char id[8];
    int salary;
public:
    Employee(const char*name, const char*id, int salary) {
      all_employees[name] = this;
      strcpy(this->name,name);
      strcpy(this->id,id);
      this->salary = salary;
    }
    virtual void pay() = 0;
    virtual void info() = 0;
};

class President : public Employee {
using Employee::Employee;
public:
    virtual void pay()
    {
        cout << "Compensation: " << salary << "+200,000 bonus will be deposited to the account" << endl;
    }
    virtual void info()
    {
        cout << "Title:President " << name << endl;
    }
};

class Director : public Employee {
using Employee::Employee;
public:
    virtual void pay()
    {
        cout << "Compensation: " << salary << "+10,000 bonus will be deposited to the account" << endl;
    }
    virtual void info()
    {
        cout << "Title:Director " << name << endl;
    }
};

class Janitor : public Employee {
using Employee::Employee;
public:
    virtual void pay()
    {
        cout << "Compensation: " << salary << "+0 bonus will be deposited to the account" << endl;
    }
    virtual void info()
    {
        cout << "Title:Janitor " << name << endl;
    }
};
void showpay(Employee *e)
{
  e->pay(); // e->vptr[0]()
}
void showinfo(Employee *e)
{
  e->info(); // e->vptr[1]()
}
char searchname[16];
Director d1("peter","201",150000);
President p1("john","123",500000);
Janitor j1("adam","209",50000);
void *eptr;
int main()
{
    printf("Please enter your employee name:");
    (void) gets(searchname);
    printf("Name:%s\n",searchname);

    if (all_employees.find(searchname) == all_employees.end())
        cout << "Employee does not exist!" << endl;
    else {
        Employee *eptr = (Employee*) all_employees.at(searchname);
        showpay(eptr);
        showinfo(eptr);
    }
}

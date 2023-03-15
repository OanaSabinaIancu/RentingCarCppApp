#include <iostream>

using namespace std;

// APPLICATION FOR CAR RENTING

// creating user class

class User
{
    protected:
        string FirstName;
        string LastName;
        int age;
        string pid;
        string username;
        string password;
        
    public:
    
    // functions needed for user (login, register ...)

    // constructors

    User();

    User(string firstName, string lastName, int age, string pid, string username, string password);

    User(const User& user);

    // destructor

    ~User();

    // overloading functions

    void readRegister(istream& in);

    void readLogin(istream& in);

    void read(istream& in);

    // reading operator overload

    friend istream& operator>> (istream& in, User &user) 
    {
        user.read(in);
        return in;
    }

    void write(ostream& out);
};

 // constructor without parameters

User::User()
{

}

// constructor with parameters 

User::User(string firstName, string lastName, int age, string pid, string username, string password) 
{
    this->FirstName = firstName;
    this->LastName = lastName;
    this->age = age;
    this->pid = pid;
    this->username = username;
    this->password = password;
}

// copy constructor

User::User(const User& user) 
{
    this->FirstName = user.FirstName;
    this->LastName = user.LastName;
    this->age = user.age;
    this->pid = user.pid;
    this->username = user.username;
    this->password = user.password;
}

// destructor

User::~User() 
{

}

// read register function

void User:: readRegister(istream& in)
{
    cout<<"Give your first name:\n";
    in>>this->FirstName;
    cout<<"\nGive your last name\n";
    in>>this->LastName;
    cout<<"\nGive your age\n";
    in>>this->age;
    cout<<"\nGive your id\n";
    in>>this->pid;

    while(this->pid.length() != 13)
    {
        cout<<"\nYour id is not valid, please enter a new one\n";
        in>>this->pid;
    }
    cout<<"\nGive your username\n";
    in>>this->username;
    cout<<"\nGive your password\n";
    in>>this->password;
}

// read login function

void User :: readLogin(istream& in)
{
    cout<<"\nGive your username\n";
    in>>this->username;
    cout<<"\nGive your password\n";
    in>>this->password;
}

// read function

void User :: read(istream& in)
{
    // user should choose a command between 1 and 2 for login or register

    int command = 0;

    while(command !=1 && command != 2)
    {
        cout<<"Select 1 for login and 2 for register: ";
        cin>>command;
        if(command == 1)
        {
            readLogin(in);
        }
        else
        {
            readRegister(in);
        }
    }
}

void User :: write(ostream& out)
{
    
}

class Admin : public User 
{
    private:
        string code;
    
    public:

    // constructors

    Admin();

    Admin(string code);

    ~Admin();
    
    // functions needed for admin users 

    // overloading citire

    
};

Admin::Admin()
{

}

Admin::Admin(string code)
{
    this->code = code;
}

Admin::~Admin()
{

}

// car class

class Car
{
    private:
        string brand;
        string model;
        string color;
        int year;
        bool rented;
}; 

int main()
{
    cout<<"Hello World";

    return 0;
}

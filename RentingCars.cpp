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
        int pid;
        string username;
        string password;
        
    public:
    
    // functions needed for user (login, register ...)

    // constructors

    User();

    User(string firstName, string lastName, int age, int pid, string username, string password);

    User(const User& user);

    // destructor

    ~User();

    // getters

    string getFirstName();

    string getLastName();

    int getAge();

    string getUsername();

    string getPassword();

    // overloading functions

    // void readRegister(istream& in);

    // void readLogin(istream& in);

    // void read(istream& in);

    // // reading operator overload

    // friend istream& operator>> (istream& in, User &user) 
    // {
    //     user.read(in);
    //     return in;
    // }

    // void write(ostream& out);
};

 // constructor without parameters

User::User()
{

}

// constructor with parameters 

User::User(string firstName, string lastName, int age, int pid, string username, string password) 
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

// getters

string User::getFirstName()
{
    return this->FirstName;
}

string User::getLastName()
{
    return this->LastName;
}

int User::getAge()
{
    return this->age;
}

string User::getUsername()
{
    return this->username;
}

string User::getPassword()
{
    return this->password;
}

// read register function

// void User:: readRegister(istream& in)
// {
//     cout<<"Give your first name:\n";
//     in>>this->FirstName;
//     cout<<"\nGive your last name\n";
//     in>>this->LastName;
//     cout<<"\nGive your age\n";
//     in>>this->age;
//     cout<<"\nGive your id\n";
//     in>>this->pid;

//     while(this->pid.length() != 13)
//     {
//         cout<<"\nYour id is not valid, please enter a new one\n";
//         in>>this->pid;
//     }
//     cout<<"\nGive your username\n";
//     in>>this->username;
//     cout<<"\nGive your password\n";
//     in>>this->password;
// }

// read login function

// void User :: readLogin(istream& in)
// {
//     cout<<"\nGive your username\n";
//     in>>this->username;
//     cout<<"\nGive your password\n";
//     in>>this->password;
// }

// read function

// void User :: read(istream& in)
// {
//     // user should choose a command between 1 and 2 for login or register

//     int command = 0;

//     while(command !=1 && command != 2)
//     {
//         cout<<"Select 1 for login and 2 for register: ";
//         cin>>command;
//         if(command == 1)
//         {
//             readLogin(in);
//         }
//         else
//         {
//             readRegister(in);
//         }
//     }
// }

// void User :: write(ostream& out)
// {
    
// }

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

void Login()
{
    string username, password;
    cout<<"Enter your username: ";
    cin>>username;
    cout<<"Enter your password: ";
    cin>>password;

    cout<<"Your username is "<<username<<" and your password is "<<password<<"\n";

    int command, admin;
    cout<<"You have an admin account? (If you have please enter 1, else enter 0) \n";
    cin>>command;
    for(;;)
    {
        if(command == 1)
        {
            cout<<"Enter the admin code: ";
            cin>>admin;
            cout<<"Welcome to our admin account!\n";
            // cout<<flush;
            break;
        }
        else
        if(command == 0)
        {
            cout<<"You can continue now.\n";
            break;
        }
        else
        if(command > 1)
        {
            cout<<"Please enter a valid command\n";
            cin>>command;
        }
    }
}

void Register()
{
    string firstName, lastName, username, password;
    int age, pid;

    cout<<"Enter your first name: ";
    cin>>firstName;
    cout<<"Enter your last name: ";
    cin>>lastName;
    cout<<"Enter your age ";
    cin>>age;
    cout<<"Enter your username ";
    cin>>username;
    cout<<"Enter your password ";
    cin>>password;

    User user(firstName, lastName, age, pid, username, password);

    cout<<"The account with username "<<user.getUsername()<<" and password "<<user.getPassword()<<" user's "<<user.getFirstName()<<" "<<user.getLastName()<<" with "<<user.getAge()<<" years old \n\n";

}

void showLoginMenu()
{
    cout<<"\t\tWelcome to renting app\n\n";

    int command = 0;

    for(;;)
    {
        cout<<"\tFor renting a car you should authenticate using one of these commands\n";
        cout<<"1. Login\n";
        cout<<"2. Register\n";
        cout<<"3. Recover password\n";

        cout<<"Enter you command: ";
        cin>>command;

        if(command == 1)
        {
            Login();
            break;
        }
        else
        if(command == 2)
        {
            Register();
            Login();
            // break;
        }
        else
        if(command == 3)
        {
            break;
        }
        else
        if(command > 3)
        {
            cout<<"Invalid command! Please enter a valid command";
            // break;
        }
    }
}

int main()
{
    showLoginMenu();
    return 0;
}

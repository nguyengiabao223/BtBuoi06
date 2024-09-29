#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Account {
protected:
string accountNumber;
string ownerName;
double balance;
public:
Account(string number,string name, double initialBalance) : accountNumber(number), ownerName(name), balance(initialBalance) {}
virtual void deposit(double amount) {
if (amount > 0) {
balance += amount;
cout << "Da nap " << amount << " vao tk ." << endl;
} else {
cout << "sotien khong hop le." << endl;
}
}
virtual bool withdraw(double amount){
    if (amount > 0 && balance >= amount ) {
        balance -= amount;
         cout << "Da rut " << amount<< " tu tai khoan " << endl;

    } else {
         cout << "Khong the rut tien. So du khong du "<< endl;
         return false;

    }
}
virtual void displayInfo() const {
    cout  << "So tai khoan " << accountNumber << endl;
    cout << "Chu tai khoan " << ownerName << endl;
    cout << " SO du " << balance << endl;

}
virtual ~Account() {}
};
class SaveingAccount : public Account {
    private :
        double interestRate;
    public: 
        SaveingAccount(string number, string name, double initialBalance, double rate ) : Account(number, name, initialBalance ), interestRate (rate) {}
        void applyInterest () {
            double interest = balance*interestRate;
            deposit(interest);
            cout << "Da cong lai: " << interest << endl;

        }
        void displayInfo() const override{
            Account::displayInfo();
            cout << "Lai suat: " <<(interestRate*100) << "%" << endl;

        }
};
class CheckingAccount : public Account {
    private :
    double overdraftLimit;
    public :
    CheckingAccount(string number, string name, double initialBalance, double limit ) : Account(number, name, initialBalance), overdraftLimit(limit) {}
    bool withdraw (double amount ) override{
        if ( amount > 0 && (balance + overdraftLimit ) >= amount ){
        balance -= amount;
        cout << "da rut " << amount << "tu tai khoan" << endl;
        return true;

    } else {
        cout << "khong the rut. vuot qua gioi han " << endl;
        return false;
    }
    }
    void displayInfo() const override{
        Account:: displayInfo();
        cout << "Gioi han chiec khau: " << overdraftLimit << endl;

    }
};
class Bank {
private:
std::vector<Account*> accounts;
public:
void addAccount(Account* account) {
accounts.push_back(account);
    }
    void displayAllAccounts() const {
        for (const auto& account : accounts) {
            account -> displayInfo();
            cout << "---------------" << endl;

        }
    }
    ~Bank () {
        for(auto account : accounts) {
            delete account;
        }
    }
   
};
int main () {
    Bank myBank;
    myBank.addAccount(new SaveingAccount("SA001","Nguyen Van A",100000, 0.05 ));
    myBank.addAccount(new SaveingAccount("SA002","Nguyen Van B",2000000, 5000000000000 ));
    cout << "Thong tin tat ca tai khoan " << endl;
    myBank.displayAllAccounts();
    return 0;
}
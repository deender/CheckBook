#include <iostream>
#include <cstring>
//HW1 Question 1 Mohammad Deen Derani

using namespace std;

struct Check{
    int CheckNum;
    string CheckMemo;
    float CheckAmount;
};

const int N = 5;

class CheckBook{
public:
    void deposit(float amount);
    void displayChecks();
    bool writeCheck(float amount);
    CheckBook():balance(0.00),numOfChecks(0){};//default
    CheckBook(int balance, int numOfChecks):balance(balance), numOfChecks(0){};
    float getBalance() const{return balance;}
private:
    float balance;
    float lastDeposit;
    Check checkLim[N];
    int checkLimit = N;//size of checkbook
    int numOfChecks;
};

int main() {
    CheckBook cb(10000,0);
    cb.writeCheck(200000);
    cout << "Balance: " << cb.getBalance() << endl;
    cb.writeCheck(6000);
    cout << "Balance: " << cb.getBalance() << endl;
    cb.writeCheck(140);
    cout << "Balance: " << cb.getBalance() << endl;
    cb.writeCheck(330);
    cout << "Balance: " << cb.getBalance() << endl;
    cb.deposit(1000);
    cout << "Deposit made! Balance after depost: " << cb.getBalance() << endl;
    cb.displayChecks();
    cout << "Balance: " << cb.getBalance() << endl;


    return 0;
}

void CheckBook::deposit(float amount) {
    balance += amount;
}

void CheckBook::displayChecks() { //function to display all of check info, probably at end of program
    cout << "Here is your check info (in order of Check Number, Check Amount, and Check Memo): " << endl;
    for (int i = numOfChecks--; i>=0, i--;){
        cout << "Check Number: " << checkLim[i].CheckNum << " Check Amount: " << checkLim[i].CheckAmount << " Check Memo: " << checkLim[i].CheckMemo << endl;
    }
}

bool CheckBook::writeCheck(float amount) { //function to write up a check
    if(amount <= balance){
        cout << "Enter the memo: " << endl;
        cin >> checkLim[numOfChecks].CheckMemo;
        checkLim[numOfChecks].CheckAmount = amount;
        checkLim[numOfChecks].CheckNum = numOfChecks + 1;
        numOfChecks++;
        balance -= amount;
    }
    else{
        return false;
    }
}

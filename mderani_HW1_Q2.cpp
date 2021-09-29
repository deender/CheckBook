#include <iostream>

//HW1 Question 2 Mohammad Deen Derani

using namespace std;

class Check{
public:
    int getNum() const {return CheckNum;}
    float getAmount() const {return CheckAmount;}
    void setNum(int n1){CheckNum = n1;}
    void setAmount(int a1){CheckAmount = a1;}
    string CheckMemo;
    Check():CheckNum(),CheckMemo(), CheckAmount(){
        static int number = 0;
        number++;
    };
private:
    int CheckNum;
    float CheckAmount;
};

const int N = 10;
static int allChecks = 0;//keeps track of all checks written
class CheckBook{
public:
    void deposit(float amount);
    void displayChecks();
    bool writeCheck(float amount);
    CheckBook() : balance(0.00), numOfChecks(0){};//default
    CheckBook(int balance, int numOfChecks):balance(balance), numOfChecks(0){
        static int const allChecks = 0;//keeps track of all checks written
    };
    Check checkLim[N]; // still having trouble with this array.
    int getAllChecks() {return allChecks;}
    float getBalance(){return balance;}
private:
    int balance;
    float lastDeposit;
    int checkLimit = N;//size of checkbook
    int numOfChecks;
};

int main() {
    CheckBook cb1(1000, 0);
    CheckBook cb2(500, 0);
    for(int i=0; i<10;i++){
        cb1.writeCheck(150);
        cb2.writeCheck(130);
    }
    cout<<"cb1 check details"<<endl;
    cb1.displayChecks();
    cout<<"cb2 check details"<<endl;
    cb2.displayChecks();
    cout<<cb1.getAllChecks()<<endl;
    cout<<cb2.getAllChecks()<<endl;

    return 0;
}

void CheckBook::deposit(float amount) {
    balance += amount;
}

void CheckBook::displayChecks() { //function to display all of check info, probably at end of program
    cout << "Here is your check info (in order of Check Number, Check Amount, and Check Memo): " << endl;
    for (int i = numOfChecks--; i>=0; i--){
        cout << "Check Number: " << checkLim[i].getNum() << " Check Amount: " << checkLim[i].getAmount() << " Check Memo: " << checkLim[i].CheckMemo << endl;
    }
}

bool CheckBook::writeCheck(float amount) { //function to write up a check
    if((amount <= balance) && (numOfChecks < N) && (allChecks < 10)){
        cout << "Enter the memo: " << endl;
        cin >> checkLim[numOfChecks].CheckMemo;
        checkLim[numOfChecks].setAmount(amount);
        checkLim[numOfChecks].setNum(numOfChecks +1);
        numOfChecks++;
        allChecks++;
        balance -= amount;
    }
    else{
        return false;
    }
}

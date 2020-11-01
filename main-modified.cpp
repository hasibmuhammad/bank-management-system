#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Account {
private:
    int acno;
    char name[50];
    int deposit;
    char type;

public:
    void createAccount(); // Function to create user account
    int generateAcNo(); // Function to generate account number for user
    void report(); // Function to make a report to show the ac holder list
    void dep(int); // Function to accept amount and add to the balance amount
    void draw(int); // Function to accept amount and subtract from the balance amount
    void showAccount(); // Function to show the data of account
    void showBalance(); // Function to show balance
    void modify(); // Function to modify user's information

    int retAcNo(); // Function to return account number
    int retDeposit(); // Function to return the deposit amount
    char retType(); // Function to return the account type
};

int Account::retAcNo(){
    return acno;
}

int Account::retDeposit(){
    return deposit;
}

char Account::retType(){
    return type;
}

void Account::dep(int amount){
    deposit += amount;
}

void Account::draw( int amount ){
    deposit -= amount;
}

void Account::showAccount(){
    cout << "\n        ====================" << endl;
    cout << "           ACCOUNT INFO.     " << endl;
    cout << "        ====================";
    cout<<"\n\n\tAccount No. : "<<acno;
	cout<<"\n\n\tAccount Holder Name : ";
	cout<< name;
	cout<<"\n\n\tType of Account : "<<type;
	cout<<"\n\n\tBalance amount : "<<deposit;
}

void Account::showBalance(){
    cout << "\n        ====================" << endl;
    cout << "           YOUR BALANCE     " << endl;
    cout << "        ====================";
    cout<<"\n\n\tBalance amount : "<<deposit;
}

int Account::generateAcNo(){
    srand(time(0));
    return rand();
}

void Account::createAccount(){
    acno = generateAcNo();
	cout <<"\nEnter The Name of The account Holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout <<"\nEnter Type of The account (C/S) : ";
	cin >> type;
	type = toupper(type);
	cout << "\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
	cin >> deposit;

	system("CLS");

    cout << "\n====================================";
    cout << "\n\nYOUR ACCOUNT NUMBER IS : " << acno;
    cout << "\n\nNOTE*: COLLECT YOUR ACCOUNT NUMBER,\n\n    YOU WILL NEED THIS ALWAYS!";
    cout << "\n\n====================================";

	cout<< "\n\n\nAccount Created...";
}

void Account::report(){
	cout<<acno<<setw(10)<<""<<name<<setw(11)<<""<<type<<setw(12)<<deposit<<endl;
}

void Account::modify(){
    cout << "\n\n\tModify Account Holder Name: ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\n\tModify Type of Account: ";
    cin >> type;
    type = toupper( type );
}

// Functions
void writeAccount();
void fetchAccounts();
void depositNwithdraw( int accountNumber, int option );
void myAccount(int accountNumber);
void balanceEnquiry( int accountNumber );
void deleteAccount( int accountNumber );
void modifyAccount( int accountNumber );
void getHelplineText();
void getFAQ();
void intro();

int main()
{
    int op, ch;

    int accountNumber;

    intro();

    do{
        system("CLS");
        cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. ACCOUNT";
        cout<<"\n\n\t02. TRANSACTION";
        cout<<"\n\n\t03. HELPLINE";
        cout<<"\n\n\t04. FAQ";
		cout<<"\n\n\t05. EXIT";
		cout<<"\n\n\tSelect Your Option (1-5) ";
        cin >> op;

        system("CLS");

        if( op == 1 ){
            cout<<"\n\n\n\tACCOUNT MENU";
            cout<<"\n\n\t10. NEW ACCOUNT";
            cout<<"\n\n\t11. CLOSE AN ACCOUNT";
            cout<<"\n\n\t12. MODIFY AN ACCOUNT";
            cout<<"\n\n\t13. MY ACCOUNT";
            cout<<"\n\n\t14. BALANCE ENQUIRY";
            cout<<"\n\n\tSelect Your Option (10-14) ";

            cin >> ch;

            system("CLS");

            switch( ch ){

                case 10:
                    writeAccount();
                    break;

                case 11:
                    cout << "\n\n\tEnter the Account No. : ";
                    cin >> accountNumber;
                    system("CLS");
                    deleteAccount( accountNumber );
                    break;

                case 12:
                    cout << "\n\n\tEnter the Account No. : ";
                    cin >> accountNumber;
                    system("CLS");
                    modifyAccount( accountNumber );
                    break;

                case 13:
                    cout << "\n\n\tEnter the Account No. : ";
                    cin >> accountNumber;
                    myAccount( accountNumber );
                    break;

                case 14:
                    cout << "\n\n\tEnter the Account No. : ";
                    cin >> accountNumber;
                    balanceEnquiry( accountNumber );
                    break;

                default:
                    cout << "\a";

            }
        }
        else if( op == 2 ){
            cout<<"\n\n\n\tTRANSACTION MENU";
            cout<<"\n\n\t21. DEPOSIT AMOUNT";
            cout<<"\n\n\t22. WITHDRAW AMOUNT";
            cout<<"\n\n\tSelect Your Option (21-22) ";

            cin >> ch;

            system("CLS");

            switch( ch ){

                case 21:
                    cout << "\n\n\tEnter the Account No. : ";
                    cin >> accountNumber;
                    depositNwithdraw( accountNumber, 1 );
                    break;

                case 22:
                    cout << "\n\n\tEnter the Account No. : ";
                    cin >> accountNumber;
                    depositNwithdraw( accountNumber, 2 );
                    break;

                default:
                    cout << "\a";

            }
        }
        else if( op == 3 ){
            cout<<"\n\n\n\tHELPLINE";
            cout << "\n\n\t==============";
            getHelplineText();
        }

        else if( op == 4 ){
            cout<<"\n\n\n\tFAQ";
            cout << "\n\n\t==============";
            getFAQ();
        }

        else if( op == 5 ){
            cout<<"\n\n\tThanks for using Bank Management System!";
        }
        cin.ignore();
        cin.get();
    }
    while( op != 5 );

    return 0;
}

// Function - Introduction
void intro()
{
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "    ====================" << endl;
    cout << "         WELCOME TO     " << endl;
    cout << "    ====================" << endl;
	cout<<"\n\t   BANK";
	cout<<"\n\n\tMANAGEMENT";
	cout<<"\n\n\t  SYSTEM";
	cout<<"\n\n\n\n     MADE BY : Group - D";
	cout<<"\n\n     University : BUBT";

	cin.get();
}

// Function - Write the account information in a file
void writeAccount(){
    Account ac;
    ofstream outFile;

    outFile.open("account.dat", ios::binary|ios::app);
    ac.createAccount();

    outFile.write( reinterpret_cast<char *> (&ac), sizeof(Account) );
    outFile.close();
}

// Fetch all data from file
void fetchAccounts(){
    Account ac;

    ifstream inFile;

    inFile.open("account.dat", ios::binary);

    if( !inFile ) {
        cout<<"File could not be open !! Press any Key...";
		return;
    }
    cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no.        NAME           Type      Balance\n";
	cout<<"====================================================\n";

    while( inFile.read( reinterpret_cast< char * > (&ac), sizeof(Account) ) ) {
        ac.report();
    }
    inFile.close();
}

// Function to withdraw and deposit amount

void depositNwithdraw(int accountNumber, int option){
    Account ac;
    int amount;
    bool found = false;
    fstream File;

    File.open("account.dat", ios::binary | ios::in | ios::out);
    if(!File){
        cout<<"File could not be open !! Press any Key...";
		return;
    }
    while( !File.eof() && found == false ) {
        File.read(reinterpret_cast <char *> (&ac), sizeof(Account));

        if( ac.retAcNo() == accountNumber ){

            system("CLS");

            ac.showAccount();

            if( option == 1 ) {
                cout << "\n\n        ====================" << endl;
                cout << "          TO DEPOSIT AMOUNT     " << endl;
                cout << "        ====================";
                cout << "\n\n\tEnter The Amount to Deposit: ";
                cin >> amount;
                ac.dep( amount );
            }

            if( option == 2 ) {
                cout << "\n\n        =====================" << endl;
                cout << "          TO WITHDRAW AMOUNT     " << endl;
                cout << "        =====================";
                cout << "\n\n\tEnter The Amount to Withdraw: ";
                cin >> amount;

                int balance = ac.retDeposit() - amount;

                if( balance < 500 && ac.retType() == 'S' || balance < 1000 && ac.retType() == 'C' ){
                    cout << "\n\n\tInsufficient Balance!";
                    return;
                }
                else{
                    ac.draw(amount);
                }
            }

            int pos=(-1)*static_cast<int>(sizeof(ac));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(Account));
            cout<<"\n\n\t Record Updated!";
            found=true;
        }
    }

    File.close();
    if( found == false ) {
        cout << "\n\n\tRecord Not Found!";
    }
}


// Function to show data depending on account number
void myAccount( int accountNumber ){
    Account ac;
    bool flag = false;

    ifstream inFile;

    inFile.open("account.dat", ios::binary);

    if( !inFile ){
        cout<<"File could not be open !! Press any Key...";
		return;
    }

    while( inFile.read( reinterpret_cast <char *> (&ac), sizeof(Account) ) ) {
        if( ac.retAcNo() == accountNumber ){
            ac.showAccount();
            flag = true;
        }
    }
    inFile.close();

    if( flag == false ) {
        cout << "\n\n\tAccount Number Doesn't exist!";
    }
}

// Function to Enquiry The Balance

void balanceEnquiry( int accountNumber ){
    Account ac;
    bool flag = false;

    ifstream inFile;

    inFile.open("account.dat", ios::binary);

    if( !inFile ){
        cout<<"File could not be open !! Press any Key...";
		return;
    }

    while( inFile.read( reinterpret_cast <char *> (&ac), sizeof(Account) ) ){
        if( ac.retAcNo() == accountNumber ) {
            ac.showBalance();
            flag = true;
        }
    }

    inFile.close();

    if( flag == false ) {
        cout << "\n\n\tAccount Number Doesn't exist!";
    }

}


// Function - to modify an account
void modifyAccount( int accountNumber ){
    Account ac;
    bool found = false;

    fstream File;
    File.open( "account.dat", ios::binary|ios::in|ios::out );

    if( !File ){
        cout<<"File could not be open !! Press any Key...";
		return;
    }

    while( !File.eof() && found == false ){
        File.read(reinterpret_cast<char *> (&ac), sizeof(Account));

        if( ac.retAcNo() == accountNumber ){
            ac.showAccount();
            cout << "\n\n        =========================" << endl;
            cout << "           MODIFY ACCOUNT INFO.     " << endl;
            cout << "        =========================";
            ac.modify();

            int pos = (-1)*static_cast<int>(sizeof(Account));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(Account));
            cout << "\n\n\tRecord Updated!";

            found = true;
        }
    }
    File.close();

    if( found == false ){
        cout << "\n\n\tRecord Not Found!";
    }
}


// Function - to delete an account from file or system
void deleteAccount( int accountNumber ){
    Account ac;

    ifstream inFile;
    ofstream outFile;

    inFile.open( "account.dat", ios::binary );
    if( !inFile ) {
        cout<<"File could not be open !! Press any Key...";
		return;
    }
    outFile.open( "Tmp.dat", ios::binary );
    inFile.seekg(0, ios::beg);

    while( inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account)) ){
        if( ac.retAcNo() != accountNumber ){
            outFile.write(reinterpret_cast<char *> (&ac), sizeof(Account) );
        }
    }
    inFile.close();
    outFile.close();
    remove("account.dat");
    rename("Tmp.dat", "account.dat");

    cout <<"\n\n\tRecord Deleted!";
}

// Function - to get helpline text
void getHelplineText(){
    cout << "\n\n\tHi,\n\n\tWelcome to the HELPLINE section. We Are Always there to help you.\n\tYour Satisfaction is our ultimate goal.\n\n\tPlease Call here *188* 24/7 to get your problems solved.\n\n\tThank You.";
}

// Function - to get frequently asked question
void getFAQ(){
    cout << "\n\n\tWelcome to the FAQ(Frequently Asked Question) section.";

    cout << "\n\n\tQ1* How to create an account?";
    cout << "\n\n\tAns: It's so simple- ";
    cout << "\n\n\t     Select *Account Option then select *New Account Option and";
    cout << "\n\n\t     Provide Valid Information. You are Done! ";

    cout << "\n\n";

    cout << "\n\n\tQ2* Is my Data safe on your system?";
    cout << "\n\n\tAns: Yes, it is. We are storing your data in binary format.";

    cout << "\n\n";

    cout << "\n\n\tQ3* Can I modify my information anytime I want?";
    cout << "\n\n\tAns: Yes, you can do this.";

    cout << "\n\n";

    cout << "\n\n\tQ4* Can I delete my account anytime?";
    cout << "\n\n\tAns: Yes, you can.";
}


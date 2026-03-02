 #include<iostream>
 #include<string>
 using namespace std;

 class Account{
 private:
  string c_name;
  int c_id;
  double balance;
public:
    void creat()
    {
        cout<<"Entre Customer name: ";
        cin.ignore();
        getline(cin, c_name);
        cout<<"Enter Customer ID: ";
        cin>>c_id;
        cout<<"Enter current balance: ";
        cin>>balance;
    }
    void deposit(double amount)
    {
        if(amount <=0)
            cout<<"Invalid amount"<<endl;
        else {
            balance+=amount;
            cout<<"Deposit successfully"<<endl;
        }
    }
void withdraw(double amount)
{
    if(amount <=0)
        cout<<"Invalid amount"<<endl;
    else if(amount>balance)
        cout<<"Insufficient balance"<<endl;
    else{
        balance-=amount;
        cout<<"Withdraw successfully"<<endl;
    }


}
void display()
{
    cout<<"Customer name: "<<c_name<<endl;
    cout<<"Customer Account ID: "<<c_id<<endl;
    cout<<"Balance: "<<balance<<endl;
}

int getID()const{
    return c_id;
}

 };

 int main()
 {
     Account A[100];
     int amount;
     int flag;
     int count=0;
     int choice;
do{
     cout<<"--*--*--*--Digital Saving Account System--*--*--*--"<<endl;
     cout<<"1.Creat Account"<<endl;
     cout<<"2.Depositing Money"<<endl;
     cout<<"3.Withdrawing Money"<<endl;
     cout<<"4.Display All Account"<<endl;
     cout<<"5.exit"<<endl;

     cout<<"Enter your choice: ";
     cin>>choice;

     switch(choice){

 case 1:
     int n;
     cout<<"Enter number of account to creat: ";
     cin>>n;
     if(count<=100){
    for(int i=0;i<n;i++){
            cout<<"Account "<<count+1<<endl;
        A[count].creat();
        count++;
    }cout<<"Account created successfully"<<endl;
     }
     else
        cout<<"No enough space!"<<endl;
    break;
 case 2:{
    int id;
    cout<<"Enter Account ID for Deposit: ";
    cin>>id;
    for(int i=0;i<=count;i++){
        if(A[i].getID()==id){
            cout<<"Entre amount to deposit: ";
            cin>>amount;
            A[i].deposit(amount);
            flag=1;
            break;
        }
    }
    if(flag!=1)
        cout<<"Invalid ID"<<endl;
    break;
 }
 case 3:{
    int id;
    flag=0;
    cout<<"Enter Account Id to withdraw: ";
    cin>>id;
    for(int i=0;i<=count;i++){
        if(A[i].getID()==id){
            cout<<"Enter amount to withdraw: ";
            cin>>amount;
            A[i].withdraw(amount);
            flag=1;
            break;
        }
    }
    if(flag!=1)
        cout<<"Invalid ID!"<<endl;
        break;
 }

 case 4:{
     int id;
     flag=0;
     cout<<"Enter id for display account detail: ";
     cin>>id;
    for(int i=0;i<=count;i++){
        if(A[i].getID()==id){
            A[i].display();
            flag=1;
            break;
        }
    }
 }

 case 5:
    cout<<"...........Thank you for visit"<<endl;
    break;
 default:
    cout<<"Invalid choice!"<<endl;
     }
}while(choice!=5);
return 0;
 }

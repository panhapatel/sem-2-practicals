#include<iostream>
#include<string>
using namespace std;

class Library{
    private:
 int B_ID;
 string B_TITLE;
 string Author;
 int NOP;

    public:
        void addbook()
        {
            cout<<"Enter Book ID: ";
            cin>>B_ID;
            cin.ignore();

            cout<<"Enetr Book title: ";
            getline(cin, B_TITLE);

            cout<<"Enter Author name: ";
            getline(cin, Author);

            cout<<"Enter number of copies: ";
            cin>>NOP;
        }

void issuebook()
{
    if (NOP>0)
    {
        NOP--;
        cout<<"Book Issued successfully"<<endl;
    }
    else
        cout<<"No copies available"<<endl;
}

void returnbook()
{
    NOP++;
    cout<<"Book return successfully"<<endl;
}

void display()
{
    cout<<endl<<"Book id: "<<B_ID<<endl;
    cout<<"Book name: "<<B_TITLE<<endl;
    cout<<"Author: "<<Author<<endl;
    cout<<"Available copies: "<<NOP<<endl;
    cout<<"------------"<<endl;
}


int getID(){
    return B_ID;
}
int getCopies()
{
    return NOP;
}
} ;

int main()
{   Library books[100];
    int count=0;
    int id;
    int choice,n;
    int flag;
do{
    cout<<"--------Library Manegement System--------"<<endl;
    cout<<"1.Add new Book"<<endl;
    cout<<"2.Issue Book"<<endl;
    cout<<"3.Return Book"<<endl;
    cout<<"4.Display total Book"<<endl;
    cout<<"5.Display total books"<<endl;
    cout<<"6.Exit"<<endl<<endl;
    cout<<"Enter choice: ";
    cin>>choice;

    switch(choice){
case 1:
    cout<<endl<<"Add Book "<<count+1<<endl;
    books[count].addbook();
    count++;
    break;
case 2:
    flag=0;
    cout<<endl<<"Enter Book id to issued: ";
    cin>>id;
    for(int i=0;i<count;i++){
        if(books[i].getID()==id){
        books[i].issuebook();
         flag=1;
        }
    }
       if(flag!=1)
        cout<<"Book not found!"<<endl;

    break;
case 3:
    flag=0;
    cout<<endl<<"Enter Book id to return: ";
    cin>>id;
    for(int i=0;i<count;i++){
        if(books[i].getID()==id){
            books[i].returnbook();
            flag=1;
        }
    }
    if(flag!=1)
    cout<<"Book not found!"<<endl;

      break;
case 4:
    for(int i=0;i<count;i++)
        books[i].display();
    break;
case 5:
{
    int totalBooks = 0;
    for(int i = 0; i < count; i++)
    {
        totalBooks = totalBooks + books[i].getCopies();
    }
    cout<<"Total available books in library: "<<totalBooks<<endl;
    break;
}
case 6:
    cout<<"exit"<<endl;
default:
    cout<<"Invalid choice"<<endl;
    break;
    }
}while(choice!=6);
return 0;
}

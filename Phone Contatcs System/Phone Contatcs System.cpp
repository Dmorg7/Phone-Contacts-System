#include <iostream>
#include<cstring>

using namespace std;

class dnode
{
public:
    char name[40]; // declaring name, number, email as charater var 
    char number[40];
    char email[40];

    dnode* prev, * next;
    dnode(char n[], char num[], char e[])
    {
        strcpy_s(name, n); // strcpy to copy on string to another
        strcpy_s(number, num);
        strcpy_s(email, e);

        prev = NULL;
        next = NULL;
    }
     class dlist;
};




class dlist
{
    dnode* top, * temp, * part; // nodes

    dnode* part1, * part2, * dro;

public:
    dnode* prevn;

    void insert();
    void sort(); // sorting algorithm

    void namesearch(char ns[20]); // calling searching functions  
    void numbersearch(char nus[30]);
    void emailsearch(char es[20]);

    void contactdelete(char cd[20]);
    
 
    void accept(); // accept function, to accept a connection socket
    void detailsdisplay(); // when called displays the inputed data
    void dataupdate(char du[11]);

    dlist()
    {
        top = NULL;
        temp = NULL;
        part = NULL;
        part1 = NULL;
        part2 = NULL;
        dro = NULL;
    }
};






void dlist::accept()
{
    char number[50]; // variables with character amount
    char email[40];
    char name[30];
    char ans;
    do
    {
        cout << "\nPlease Enter Contact Name: ";
        cin >> name;

        cout << "Please Enter Contact Number: ";
        cin >> number;

        while (strlen(number) != 11)
        {
            cout << "You Must Enter A Valid Number: ";
            cin >> number;
        }

        cout << "Please Enter Contact Email Address: ";
        cin >> email;

        temp = new dnode(name, number, email); // stores the users input in the list
        if (top == NULL)
        {
            top = temp;
        }
        else
        {
            part = top;
            while (part->next != NULL)
            {
                part = part->next;
            }
            part->next = temp;
            temp->prev = part;
        }

        cout << "Confirm Details Entered?";
        cin >> ans;

    } while (ans == 'n');

}




void dlist::detailsdisplay() // displays the users inputs
{
    part = top;
    while (part != NULL)
    {
        cout << "\n\nName:\t" << part->name;
        cout << "\nNumber:\t" << part->number;
        cout << "\nEmail:\t" << part->email;
        part = part->next; // list gets moved forward
    }
}




void dlist::insert()
{
    accept();
}




void dlist::sort() // sorting alogrithm in alphabetical order
{
    dnode* i, * s;
    int temp;
    char n[10];
    for (i = top; i->next != NULL; i = i->next)
    {
        for (s = i->next; s != NULL; s = s->next)
        {
            temp = strcmp(i->name, s->name);
            if (temp > 0)
            {
                strcpy_s(n, i->name);
                strcpy_s(i->name, s->name);
                strcpy_s(s->name, n);
            }
        }
    }

}






void dlist::contactdelete(char s[20]) // deleting the contact infromation
{
    int cd = 0;
    part = top;
    while (part != NULL)
    {
        if (strcmp(s, part->name) == 0)
        {
            cd = 1;
            break;
        }
        else
        {
            cd = 2;
        }
        part = part->next;
    }

    if (cd == 1 && part != top && part->next != NULL)
    {
        part->prev->next = part->next;
        part->next->prev = part->prev;
        delete(part);
        cout << "Contact Has Been Deleted\n\n"; // searches through the list and removes previously inputted data
    }

    if (part == top)
    {
        top = top->next;
        top->prev = NULL;
        delete(part);
        cout << "Contact Has Been Deleted\n\n";
    }

    if (part->next == NULL)
    {
        part->prev->next = NULL;
        part->prev = NULL;
        delete(part);
        cout << "Contact Has Been Deleted\n\n";
    }

    if (cd == 2)
    {
        cout << "Name Not Recognised"; // invalid input message
    }
}







void dlist::namesearch(char na[10]) // name search using user input
{
    dro = top;
    while (dro != NULL)
    {
        if (strcmp(na, dro->name) == 0)
        {
            cout << "Contact:\n" << endl; 
            cout << "\n\nName:\n" << dro->name;
            cout << "\nNumber:\n" << dro->number;
            cout << "\nEmail:\n" << dro->email;

        }
        dro = dro->next;
    }
}




void dlist::numbersearch(char num[20]) // number search using user input
{
    part = top;
    while (part != NULL)
    {
        if (strcmp(num, part->number) == 0)
        {
            cout << "Contact:" << endl;
            cout << "\n\nName: " << part->name;
            cout << "\nNumber: " << part->number;
            cout << "\nEmail: " << part->email;

        }
        part = part->next;
    }
}





void dlist::emailsearch(char em[20]) // email search using user input
{
    part = top;
    while (part != NULL)
    {
        if (strcmp(em, part->email) == 0)
        {
            cout << "Email Contact:\n" << endl;
            cout << "\n\nName: " << part->name;
            cout << "\nNumber: " << part->number;
            cout << "\n\Email: " << part->email;

        }
        part = part->next;
    }
}






void dlist::dataupdate(char n[20]) // updating stored data
{
    char ans;
    int du;
    part = top;

    while (part != NULL)
    {
        if (strcmp(n, part->name) == 0)
        {

            do
            {
                cout << "\nUpdate a Contact\n1.Contact Name\n2.Contact Number\n3.Contact Email\n"; // user should choose bewteen the number for their input
                cin >> du;
                switch (du)
                {
                case 1:
                    cout << "Enter New Name: \n"; // Seraches for the contacts name and changes the data in the list using the users input
                    cin >> part->name;
                    break;
                case 2:
                    cout << "Enter New Number \n"; // Seraches for the contacts number and changes the data in the list using the users input
                    cin >> part->number;
                    while (strlen(part->number) != 11)
                    {
                        cout << "Please Enter a Valid Number: \n"; // while loop for inputting a phone number in the correct number format (11 numbers)
                        cin >> part->number;
                    }
                    break;
                case 3:
                    cout << "Enter New Email: \n"; // Seraches for the contacts email and changes the data in the list using the users input
                    cin >> part->email;
                    break;
                }
                cout << "Are You Happy With Details Entered? \n";
                cin >> ans;
            } while (ans == 'n');
        }
        part = part->next;
    }
}





int main() // main function/UI
{
    char n[20];
    char name[10];
    char number[11];
    char email[20];

    dlist d1; // 
    char ans; // user input var
    int ch, a;

    cout << "********* Phone Contacts*********";
    cout << "\n\nPlease Enter Your Name: \n"; // User can enter their own name for welcome message purpose
    cin.getline(name, 20);
    cout << "\n\n!!!!!!!!!Welcome " << name << "!!!!!!!!";

    d1.accept();
    d1.sort();
    do
    {
        cout << "\n\n\n\n1) Contacts Details Display\n2) Add New Contact\n3) Update Contacts\n4) Delete Contact\n5) Search\n"; // user input required for the systems section
        cin >> ch;
        switch (ch)
        {
        case 2:
            d1.insert();
            d1.sort();
            break;

        case 1:
            d1.sort(); // sorting algorithm function
            d1.detailsdisplay(); // display contacts
            break;
        case 3:

            cout << "\n\nEnter Name of Contact To Update\n";
            cin >> n;
            d1.dataupdate(n);
            d1.sort();
            break;
        case 4:
            cout << "\nEnter Contact Name To Delete\n";
            cin >> name;
            d1.contactdelete(name);
            break;
        case 5:
            do
            {
                cout << "1.Name Search\n2.Number Search\n3.Email Search\n"; // seraching do while loop
                cin >> a;
                switch (a)
                {
                case 1:
                    cout << "Enter Name: \n";
                    cin >> name;
                    d1.namesearch(name);
                    break;
                case 2:
                    cout << "Enter Number: \n";
                    cin >> number;
                    d1.numbersearch(number);
                    break;
                case 3:
                    cout << "Enter Email: \n";
                    cin >> email;
                    d1.emailsearch(email);
                    break;
                default:cout << "\nInvalid Input, Please Enter Valid Input\n";
                }
                cout << "Continue Contact Serach? ";
                cin >> ans;
            } while (ans == 'y');
            break;
            d1.detailsdisplay();
            break;

        default:cout << "\nInvalid Input, Please Enter Valid Input\n";
        }
        cout << "\n\nContinue Using Contacts System? ";
        cin >> ans;
    } while (ans == 'y');
}
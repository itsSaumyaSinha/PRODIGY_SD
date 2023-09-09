#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

string name;
long long int phone_no;
string email_id;
char choice;
string edit_name;
int value = 0;

void Addnew()
{

    ofstream fileout;
    fileout.open("contactdetails.txt", ios::out | ios::app);
    // stored in standard ios
    while (true)
    {
        cout << "Enter Name:\t";
        cin >> name;
        cout << "\nEnter phone no:\t";
        cin >> phone_no;
        cout << "\nEnter email_id:\t";
        cin >> email_id;
        fileout << name << endl
                << phone_no << endl
                << email_id << endl;
        cout << "\nDO YOU WANT TO ENTER MORE??";
        cin >> choice;

        if (choice == 'n')
        {
            break;
        }
    }

    fileout.close();
}

void contactdisplay()
{
    ifstream filein;
    filein.open("contactdetails.txt");

    while (filein >> name >> phone_no >> email_id)
    {
        cout << "\nNAME:\t" << name;
        cout << "\nPHONE_NO:\t" << phone_no;
        cout << "\nEMAIL_ID:\t" << email_id;
        getch();
    }

    cout << "\n--NO MORE DATA--\n";
    filein.close();
}

void editcontact()
{
    ifstream file1;
    file1.open("contactdetails.txt");
    ofstream file2;
    file2.open("temp.txt");
    cout << "\nWHICH CONTACT YOU WANT TO EDIT??: \t";
    contactdisplay();
    cout << "\nENTER NAME:\t";
    cin >> edit_name;
    while (file1 >> name >> phone_no >> email_id)
    {
        if (name == edit_name)
        {
            cout << "\nENTER NAME:\t";
            cin >> name;
            cout << "\nENTER PHONE_NO:\t";
            cin >> phone_no;
            cout << "\nENTER EMAIL_ID\t";
            cin >> email_id;
            file2 << name << endl
                  << phone_no << endl
                  << email_id << endl;
            cout << "\nDONE\n";
        }
        else
        {
            file2 << name << endl
                  << phone_no << endl
                  << email_id << endl;
            cout << "\nCOPIED\n";
        }
    }

    file1.close();
    file2.close();
    remove("contactdetails.txt");
    rename("temp.txt", "contactdetails.txt");
}

void deletecontact()
{
    cout << "\nWHICH CONTACT YOU WANT TO DELETE??\n";
    contactdisplay();
    cout << "ENTER NAME:\n";
    cin >> edit_name;
    ifstream file1;
    file1.open("contactdetails.txt");
    ofstream file2;
    file2.open("temp.txt");
    while (file1 >> name >> phone_no >> email_id)
    {
        if (name == edit_name)
        {
            cout << "\nCONTACT DELETED\n";
        }
        else
        {
            file2 << name << endl
                  << phone_no << endl
                  << email_id << endl;
        }
    }
    file1.close();
    file2.close();
    remove("contactdetails.txt");
    value = rename("temp.txt", "contactdetails.txt");
    if (value == 0)
    {
        cout << "\nsSUCCESSFULLY RENAMED\n";
    }
    else
    {
        cout << "RENAME FAILED";
    }
}

void deletefile()
{
    remove("contactdetails.txt");
    remove("temp.txt");
    cout << "DELETED SUCCESSFULLY\n";
}

int main()
{
    int operation;
    while (true)
    {
        cout << "WHAT DO YOU WANT TO PERFORM??" << endl
             << "1: TO STORE NEW CONTACT " << endl
             << "2: TO EDIT THE CONTACT " << endl
             << "3: TO VIEW THE CONTACTS " << endl
             << "4: DELETE CONTACT " << endl
             << "5: DELETE FILE " << endl;
        cin >> operation;

        switch (operation)
        {
        case 1:
            Addnew();
            break;
        case 2:
            editcontact();
            break;
        case 3:
            contactdisplay();
            break;
        case 4:
            deletecontact();
            break;
        case 5:
            deletefile();
            break;
        default:
            cout << "\nINVALID\n";
        }
        cout << "DO YOU WANT TO CONTINUE WITH THE OPERATION:??\t";
        cin >> choice;
        if (choice == 'y')
        {
            continue;
        }
        else
            break;
    }
    cout << "\n--ENDED--\n";
    return 0;
}
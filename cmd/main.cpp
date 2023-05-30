//Music Inventory System : Find the Songs that you like !

//including the necessary header files

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#include <string>
#pragma comment(lib, "winm.lib")
// #include <cstdlib>
void Play();

using namespace std;

//function to check the login credentials

bool isLoggedIn()
{
    string username, password;
    string un, pw; // comparison strings

    cout << "Enter a username: ";
    cin >> username; 
    cout << "Enter a password: ";
    cin >> password;

    ifstream read(username + ".txt"); // ifstream reads a file 
    getline(read, un); // reads the username 
    getline(read, pw); // reads the password

    if(un == username && pw == password) // if both un & username and pw & password are the same, true
    {
        return true;
    }
    else
    {
        return false;
    }
}

class admin
{
    protected:
        string username;
        string password;
    public:
        //a pure virtual function so that each inherited class makes it own menu
        virtual void menu()=0;
};

// An inherited class made for Developer section

class Employee : public admin
{
    protected:
        string name, empID, designation, address;
        long long int contactNo;

    public:
        void menu();//it displays the menu of Employees section
        void addEmp(); // it adds a employees
        void displayEmp(); // it displays all the employees details 
        void searchEmp();   //it searches for a employee and show its details
        void deleteEmp(); //it deletes a record of employee
};

// An inherited class made for MusicAl section

class MusicAl : public admin
{
    protected:
        string songId, sname,artist, album,genre,year;

    public:
        void menu();    // it displays the menu
        void addMusic();
        void displayMusic();
        void searchMusic();
        void deleteMusic();
};

// An inherited class made for contract section

class Contracts : public admin
{
    protected:
        string cID, companyName, Player, sID, Song;
        int cyear, expires;

    public:
        void menu();
        void addCon();
        void displayCon();
        void searchCon();
        void deleteCon();
};

//a class for performing user operations

class player : public MusicAl, public Contracts
{
    public:
    void menu();
    void displayPlay();
    void searchPlay();
    void where();
};

int main()
{
    int try1 = 0, try2 = 0, try3 = 0;
    int choice;
    string usernameA;
    string passwordA;
    Employee e1;
    MusicAl m1;
    Contracts c1;
    while (try3 == 0)
    {
        system("cls");
        cout << "******* Welcome to Music Inventory *******" << endl;
        cout << "Please enter your choice:" << endl;
        cout << "1. Admin" << endl;
        cout << "2. User" << endl;
        cout << "3. Go to Music Player and Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "***** Welcome To The Admin Page ******";
            cout << "\nEnter your Credentials :\n";
            while (try1 == 0)
            {
                cout << "Enter your username:\t" << endl;
                cin >> usernameA;
                if (usernameA == "admin123")
                {
                    cout << "Enter your password: \t" << endl;
                    cin >> passwordA;
                    if (passwordA == "12345")
                    {
                        cout << "\n******** ACCESS GRANTED! *******\n"<< endl;
                        cout << "Press any key to continue:\t" << endl;
                        getch();
                        try1 = 1;
                        while (try2 == 0)
                        {
                            system("cls");
                            cout << "Please Enter your choice:\n";
                            cout << "1. Employees Details \n";
                            cout << "2. Music Albums \n";
                            cout << "3. Contracts\n";
                            cout << "4. Exit\n";
                            cin >> choice;
                            switch (choice)
                            {
                            case 1:
                                e1.menu();
                                break;
                            case 2:
                                m1.menu();
                                break;
                            case 3:
                                c1.menu();
                                break;
                            case 4:
                                cout<<"Existing the Admin"<<endl;
                                getch();
                                main();
                                break;
                            }
                        }
                    }
                    else
                    {
                        printf("Invalid password. Try again!\n");
                    }
                }
                else
                {
                    printf("Invalid username. Try again!\n");
                }
            }
            break;

        case 2:
            cout << "***** Welcome To The User Page ******" << endl;
            cout << "-------------------------------" << endl;
            cout << "1. Register" << endl;
            cout << "2. Login" << endl;
            cout << endl;
            cout << "Your choice: ";
            cin >> choice; 

            if(choice == 1)
            {
                string username, password;

                cout << "Registration: " << endl;
                cout << endl;
                cout << "Select a username: "; 
                cin >> username;
                cout << "Select a password: ";
                cin >> password;

                ofstream file; // ofstream creates a file to write in it
                file.open(username + ".txt"); //concatenation
                file << username << endl << password;
                file.close();
                cout << "Welcome " << username << "!" << endl;
                player p1;
                p1.menu();
            }
            else if(choice == 2) // if user chooses to login
            {
                bool status = isLoggedIn();

                if(!status) // if isLoggedIn() returns false
                {
                    system("cls");
                    cout << endl;
                    cout << "Invalid login!" << endl;
                    getch();
                    main();
                    return 0;
                }
                else // if isLoggedIn() returns true, the dashboard is displayed
                {
                    cout << "Successfully logged in!" << endl;
                    cout << endl;
                    // Display dashboard:
                    cout << "Welcome back!" << endl;
                    cout << endl;
                    cout << "Press any key to continue:\t" << endl;
                    getch();
                    player p1;
                    p1.menu();
                    return 1;
                }
            }
                        
            break;

        case 3:
            getch();
            cout<<"Playing Music and Existing the program\n";
            Play();
            goto end;
            break;
        }
    }

    end:
    return 0;
}

// menu functions of each class
// menu of employee section

void Employee::menu()
{

    int try1 = 0;
    int choice1;
    char x;
    system("cls");
    cout << "IN EMPLOYEE DETAILS SECTION" << endl;
    while (try1 == 0)
    {

        cout << "\nPlease Enter your choice:\n";
        cout << "1. Add an Employee Entry details\n";
        cout << "2. Display all Employees details\n";
        cout << "3. Search an Employee details \n";
        cout << "4. Delete an Employee details\n";
        cout << "5. Exit\n";
        cin >> choice1;
        if (choice1 == 1)
        {
            do
            {
                addEmp();
                cout << "\n\n\t\t\t Add Another Record (Y, N) : ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
        }
        else if (choice1 == 2)
        {
            displayEmp();
        }
        else if (choice1 == 3)
        {
            searchEmp();
        }
        else if (choice1 == 4)
        {
            deleteEmp();
        }
        else if (choice1 == 5)
        {
            cout << "Exiting Employee section " << endl;
            try1 = 1;
        }
        else
        {
            cout<<"Invalid choice";
        }
        getch();
    }
}

// menu of Music section
void MusicAl::menu()
{

    int try1 = 0;
    int choice1;
    char x;
    system("cls");
    cout << "IN MUSIC ALBUM SECTION" << endl;
    while (try1 == 0)
    {

        cout << "\nPlease Enter your choice:\n";
        cout << "1. Add a Music Album details\n";
        cout << "2. Display a Music Album details\n";
        cout << "3. Search a Music Album details \n";
        cout << "4. Delete a Music Album details\n";
        cout << "5. Exit\n";
        cin >> choice1;
        if (choice1 == 1)
        {
            do
            {
                addMusic();
                cout << "\n\n\t\t\t Add Another Record (Y, N) : ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
        }
        else if (choice1 == 2)
        {
            displayMusic();
        }
        else if (choice1 == 3)
        {
            searchMusic();
        }
        else if (choice1 == 4)
        {
            deleteMusic();
        }
        else if (choice1 == 5)
        {
            try1 = 1;
        }
        else
        {
            cout<<"Invalid choice";
        }
    }
}

// menu of Contracts section

void Contracts::menu()
{
    int try1 = 0;
    int choice1;
    char x;
    system("cls");
    cout << "In Contract and Agreement section" << endl;
    while (try1 == 0)
    {
        cout << "\nPlease Enter your choice:\n";
        cout << "1. Add a Contract Entry \n";
        cout << "2. Display all Contracts details\n";
        cout << "3. Search an Contract details \n";
        cout << "4. Delete an Contract details\n";
        cout << "5. Exit\n";
        cin >> choice1;
        if (choice1 == 1)
        {
            do
            {
                addCon();
                cout << "\n\n\t\t\t Add Another Record (Y, N) : ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
        }
        else if (choice1 == 2)
        {
            displayCon();
        }
        else if (choice1 == 3)
        {
            searchCon();
        }
        else if (choice1 == 4)
        {
            deleteCon();
        }
        else if (choice1 == 5)
        {
            try1 = 1;
        }
        else
        {
            cout<<"Invalid choice";
        }
    }
}

// member functions of employee class

void Employee ::addEmp()
{
    system("cls");
    fstream file;
    cout << "*******************************" << endl;
    cout << "\t\t\tAdd Employee Details" << endl;
    cout << "\t\t\tEnter Name: ";
    cin >> name;
    cout << "\t\t\tEnter Employee Id: ";
    cin >> empID;
    cout << "\t\t\tEnter designation:";
    cin >> designation;

    cout << "\t\t\tEnter Address: ";
    cin >> address;

contact:
    cout << "\t\t\tEnter Contact No:";
    cin >> contactNo;
    if (contactNo < 1000000000 || contactNo > 9999999999)
    {
        cout << "\t\t\t Please Enter Only 10 Digits..." << endl;
        goto contact;
    }
    file.open("employee.txt", ios::app | ios::out);
    file << " " << name << " " << empID<< " " << designation << " "<< " " << address << " " << contactNo << "\n";
    file.close();
}

void Employee ::displayEmp()
{
    system("cls");
    fstream file;
    int total = 1;
    cout << "\n---------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Displaying Employee Records -----------------------------" << endl;
    file.open("employee.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Record Found... ";
        file.close();
    }
    else
    {
        file >> name >> empID >> designation >> address >> contactNo;
        while (!file.eof())
        {
            cout << "\n\n\t\t\tEmployee No: " << total++ << endl;
            cout << "\t\t\tName: " << name << "\n";
            cout << "\t\t\tRoll No.: " << empID << "\n";
            cout << "\t\t\tCourse: " << designation << "\n";
            cout << "\t\t\tContact No.: " << contactNo << "\n";
            cout << "\t\t\tAddress: " << address << "\n";
            file >> name >> empID >> designation >> address >> contactNo;
        }
        if (total == 0)
        {
            cout << "\n\t\t\tNo Data is Present..." << endl;
        }
    }
    file.close();
}

void Employee ::searchEmp()
{
    system("cls");
    fstream file;
    int found = 0;
    int total = 1;
    file.open("employee.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Employee Search Data --------------------------------------------" << endl;
        cout << "\n\t\t\tNo Data is Present... " << endl;
    }
    else
    {
        string emp_ID;
        cout << "\n-----------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Employee Search Table -----------------------------------" << endl;
        cout << "\nEnter Employee ID of the employee which you want to search: ";
        cin >> emp_ID;
        file >> name >> empID >> designation >> address >> contactNo;
        while (!file.eof())
        {
            if (empID == emp_ID)
            {
                cout << "\n\n\t\t\tEmployee No: " << total++ << endl;
                cout << "\t\t\tName: " << name << "\n";
                cout << "\t\t\tRoll No.: " << empID << "\n";
                cout << "\t\t\tCourse: " << designation << "\n";
                cout << "\t\t\tContact No.: " << contactNo << "\n";
                cout << "\t\t\tAddress: " << address << "\n";
                file >> name >> empID >> designation >> address >> contactNo;
                found++;
            }
            file >> name >> empID >> designation >> address >> contactNo;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Employee empID Not Found....";
        }
        file.close();
    }
}

void Employee ::deleteEmp()
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string emp_ID;
    cout << "\n-----------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Employee Details --------------------------------" << endl;
    file.open("employee.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Employee ID of the employee which you want to search: ";
        cin >> emp_ID;
        file1.open("buffer.txt", ios::app | ios::out);
        file >> name >> empID >> designation >> address >> contactNo;
        while (!file.eof())
        {
            if (empID != emp_ID)
            {
                file1 << " " << name << " " << empID << " " << designation << " " << address << " " << contactNo << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> empID >> designation >> address >> contactNo;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Employee empID Not Found....";
        }
        file1.close();
        file.close();
        remove("employee.txt");
        rename("buffer.txt", "employee.txt");
    }
}

//**********member functions of Music class*********

void MusicAl ::addMusic()
{
    system("cls");
    fstream file;
    cout << "************************" << endl;
    cout << "\t\t\tAdd Music Details" << endl;
    cout << "\t\t\tEnter SongID: ";
    cin >> songId;
    cout << "\t\t\tEnter Song name: ";
    cin >> sname;
    cout << "\t\t\tEnter Artist:";
    cin >> artist;
    cout << "\t\t\tEnter Album: ";
    cin >> album;
    cout << "\t\t\tEnter Genre: ";
    cin >> genre;
    cout << "\t\t\tEnter Year of Release: ";
    cin >> year;
    file.open("musical.txt", ios::app | ios::out);
    file << " " << songId << " " << sname<< " " << artist << " " << album << " " << genre<<" "<<year<<"\n";

    file.close();
}

void MusicAl ::displayMusic()
{
    system("cls");
    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Displaying Music Records --------------------------------------------" << endl;
    file.open("musical.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Record Found... ";
        file.close();
    }
    else
    {
        file >> songId >> sname >> artist >> album >> genre>>year;
        while (!file.eof())
        {
            cout << "\n\n\t\t\tSong No: " << total++ << endl;
            cout << "\t\t\tSongID : " << songId << "\n";
            cout << "\t\t\tName: " << sname << "\n";
            cout << "\t\t\tArtist: " << artist << "\n";
            cout << "\t\t\tAlbum: " << album << "\n";
            cout << "\t\t\tGenre: " << genre << "\n";
            cout << "\t\t\tYear of Release: " << year << "\n";
            file >> songId >> sname >> artist >> album >> genre>>year;
        }
        if (total == 0)
        {
            cout << "\n\t\t\tNo Data is Present..." << endl;
        }
    }

    file.close();
}

void MusicAl ::searchMusic()
{
    system("cls");
    fstream file;
    int found = 0;
    int total = 1;
    file.open("musical.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Music Search Data --------------------------------------------" << endl;
        cout << "\n\t\t\tNo Data is Present... " << endl;
    }
    else
    {
        string song_Id;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Music Search Table --------------------------------------------" << endl;
        cout << "\nEnter song ID which you want to search: ";
        cin >> song_Id;
        file >> songId >> sname >> artist >> album >>genre>>year;
        while (!file.eof())
        {
            if (songId == song_Id)
            {
                cout << "\n\n\t\t\tSong No: " << total++ << endl;
                cout << "\t\t\tSongID : " << songId << "\n";
                cout << "\t\t\tName: " << sname << "\n";
                cout << "\t\t\tArtist: " << artist << "\n";
                cout << "\t\t\tAlbum: " << album << "\n";
                cout << "\t\t\tGenre: " << genre << "\n";
                cout << "\t\t\tYear of Release: " << year << "\n";
                found++;
            }
            file >> songId >> sname >> artist >> album >> genre>>year;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Music Not Found....";
        }
        file.close();
    }
}

void MusicAl ::deleteMusic()
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string song_Id;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Music Details ------------------------------------------" << endl;
    file.open("musical.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Id of the song which you want Delete Data: ";
        cin >> song_Id;
        file1.open("buffer.txt", ios::app | ios::out);
        file >> songId >> sname >> artist >> album >> genre>>year;
        while (!file.eof())
        {
            if (songId != song_Id)
            {
                file1 << " " << songId << " " << sname << " " << artist << " " << album << " " << genre<<" "<<year << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> songId >> sname >> artist >> album >> genre>>year;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Music Not Found....";
        }
        file1.close();
        file.close();
        remove("musical.txt");
        rename("buffer.txt", "musical.txt");
    }
}

//********member functions of Contract class********

void Contracts::addCon()
{
    system("cls");
    fstream file;
    cout << "***********************" << endl;
    cout << "\t\t\tAdd Contract Details" << endl;
    cout << "\t\t\tEnter Contract Id: ";
    cin >> cID;
    cout << "\t\t\tEnter Company Name: ";
    cin >> companyName;
    cout << "\t\t\tEnter Player associated with it: ";
    cin >> Player;
    cout << "\t\t\tEnter Song Id: ";
    cin >> sID;
    cout << "\t\t\tEnter song name: ";
    cin >> Song;
    cout << "\t\t\tEnter the year from which it started:";
    cin >> cyear;
    cout << "\t\t\tEnter the year in which it expires: ";
    cin >> expires;
    file.open("contract.txt", ios::app | ios::out);
    file << " " << cID << " " << companyName << " " << Player << " " << sID <<" " << Song << " " << cyear << " " << expires << " " <<"\n";
    file.close();
}

void Contracts::displayCon()
{

    system("cls");
    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Displaying Contract Records --------------------------------------------" << endl;
    file.open("contract.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Record Found... ";
        file.close();
    }
    else
    {
        file >> cID >> companyName >> Player >> sID >> Song >> cyear >> expires;
        while (!file.eof())
        {
            cout << "\n\n\t\t\tContract No: " << total++ << endl;
            cout << "\t\t\tID: " << cID << "\n";
            cout << "\t\t\tCompany Name: " << companyName << "\n";
            cout << "\t\t\tPlayer: " << Player << "\n";
            cout << "\t\t\tSong Id: " << sID << "\n";
            cout << "\t\t\tSong : " << Song << "\n";
            cout << "\t\t\tYear in which it started: " << cyear << "\n";
            cout << "\t\t\tExpires on : " << expires << "\n";
            file >> cID >> companyName >> Player >> sID >> Song >> cyear >> expires;
        }
        if (total == 0)
        {
            cout << "\n\t\t\tNo Data is Present..." << endl;
        }
    }

    file.close();
}

void Contracts::searchCon()
{
    system("cls");
    fstream file;
    int found = 0;
    int total = 1;
    file.open("contract.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Contract Search Data --------------------------------------------" << endl;
        cout << "\n\t\t\tNo Data is Present... " << endl;
    }
    else
    {
        string ID1;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Contract Search Table --------------------------------------------" << endl;
        cout << "\nEnter Id of the contract which you want to search: ";
        cin >> ID1;
        file >> cID >> companyName >> Player >> sID >> Song >> cyear >> expires;
        while (!file.eof())
        {
            if (cID == ID1)
            {
                cout << "\n\n\t\t\tContract No: " << total++ << endl;
                cout << "\t\t\tID: " << cID << "\n";
                cout << "\t\t\tCompany Name: " << companyName << "\n";
                cout << "\t\t\tPlayer: " << Player << "\n";
                cout << "\t\t\tSong Id: " << sID << "\n";
                cout << "\t\t\tSong : " << Song << "\n";
                cout << "\t\t\tYear in which it started: " << cyear << "\n";
                cout << "\t\t\tExpires on : " << expires << "\n";
                found++;
            }
            file >> cID >> companyName >> Player >> sID >> Song >> cyear >> expires;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Contract ID Not Found....";
        }
        file.close();
    }
}

void Contracts::deleteCon()
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string ID1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Contract Details ------------------------------------------" << endl;
    file.open("contract.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter ID of Contract which you want to Delete Data: ";
        cin >> ID1;
        file1.open("buffer.txt", ios::app | ios::out);
        file >> cID >> companyName >> Player >> sID >> Song >> cyear >> expires;
        while (!file.eof())
        {
            if (cID != ID1)
            {
                file << " " << cID << " " << companyName << " " << Player << " " << sID <<" " << Song << " " << cyear << " " << expires << " " <<"\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Deleted Data";
            }
        file >> cID >> companyName >> Player >> sID >> Song >> cyear >> expires;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Contract No. Not Found....";
        }
        file1.close();
        file.close();
        remove("contract.txt");
        rename("buffer.txt", "contract.txt");
    }
}

/// menu for user section

void player::menu()
{

    int try1 = 0;
    int choice1;
    char x;
    system("cls");
    cout << "In User Section" << endl;
    while (try1 == 0)
    {
        cout << "\nPlease Enter your choice:\n";
        cout << "1. Display all Music Albums \n";
        cout << "2. Search songs of a singer \n";
        cout << "3. Find the player to listen to the song\n";
        cout << "4. Exit\n";
        cin >> choice1;
        if (choice1 == 1)
        {
            displayPlay();
        }
        else if (choice1 == 2)
        {
            searchPlay();
        }
        else if (choice1 == 3)
        {
            where();
        }
        else if (choice1 == 4)
        {
            try1 = 1;
        }
        else
        {
            cout << "Invalid choice";
        }
    }
}

void player ::displayPlay()
{
    system("cls");
    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Displaying Music Records --------------------------------------------" << endl;
    file.open("musical.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Record Found... ";
        file.close();
    }
    else
    {
        file >> songId >> sname >> artist >> album >> genre>>year;
        while (!file.eof())
        {
            cout << "\n\n\t\t\tSong No: " << total++ << endl;
            cout << "\t\t\tSongID : " << songId << "\n";
            cout << "\t\t\tName: " << sname << "\n";
            cout << "\t\t\tArtist: " << artist << "\n";
            cout << "\t\t\tAlbum: " << album << "\n";
            cout << "\t\t\tGenre: " << genre << "\n";
            cout << "\t\t\tYear of Release: " << year << "\n";
            file >> songId >> sname >> artist >> album >> genre>>year;
        }
        if (total == 0)
        {
            cout << "\n\t\t\tNo Data is Present..." << endl;
        }
    }

    file.close();   
}

void player ::searchPlay()
{
    system("cls");
    fstream file;
    int found = 0;
    int total = 1;
    file.open("musical.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Music Search Data --------------------------------------------" << endl;
        cout << "\n\t\t\tNo Data is Present... " << endl;
    }
    else
    {
        string song_Id;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Music Search Table --------------------------------------------" << endl;
        cout << "\nEnter the song ID of the singer which you want to search: ";
        cin >> song_Id;
        file >> songId >> sname >> artist >> album >>genre>>year;
        while (!file.eof())
        {
            if (songId == song_Id)
            {
                cout << "\n\n\t\t\tSong No: " << total++ << endl;
                cout << "\t\t\tSongID : " << songId << "\n";
                cout << "\t\t\tName: " << sname << "\n";
                cout << "\t\t\tArtist: " << artist << "\n";
                cout << "\t\t\tAlbum: " << album << "\n";
                cout << "\t\t\tGenre: " << genre << "\n";
                cout << "\t\t\tYear of Release: " << year << "\n";
                found++;
            }
            file >> songId >> sname >> artist >> album >>genre>>year;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Music Not Found....";
        }
        file.close();
    }
}

void player::where(){

    system("cls");
    fstream file;
    int found = 0;
    int total = 1;
    file.open("contract.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Music Player Search Data --------------------------------------------" << endl;
        cout << "\n\t\t\tNo Data is Present... " << endl;
    }
    else
    {
        string song_Id;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Music Player Search Table --------------------------------------------" << endl;
        cout << "\nEnter the song ID of the song which you want to search: ";
        cin >> song_Id;
        file >> cID >> companyName >> Player >> sID >> Song >> cyear >> expires;
        while (!file.eof())
        {
            if (sID == song_Id)
            {
                cout << "\n\n\t\t\tPlayer No: " << total++ << endl;
                cout << "\t\t\tPlayer : " << Player << "\n";
                found++;
            }
            file >> cID >> companyName >> Player >> sID >> Song >> cyear >> expires;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Music Not Found....";
        }
        file.close();
    }
}
void Play(){
  
    // songs are
    // relaxing-birds-and-piano-music-137153.wav
    //  endless-by-prabajithk-118998.wav
    //  inspirational-piano-141480.wav
    // piano-moment-9835.wav
    // slow-motion-121841.wav

    cout << "-------------------choose a song--------------------------------" << endl;
    cout << "1-> relaxing-birds-and-piano" << endl;
    cout << "2-> endless-by-prabajithk" << endl;
    cout << "3-> inspirational-piano " << endl;
    cout << "4-> piano-moment" << endl;
    cout << "5-> slow-motion" << endl;
    int x;
    cout << " please enter the key corresponding to the song you want to play ";
    cin >> x;
    if (x == 1)
    {

        PlaySound(TEXT("relaxing-birds-and-piano-music-137153.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);


        string input;
        getline(cin, input);
        PlaySound(0, 0, 0);
        cout<<"Press any key to play the desired song."<<endl;
        

        getline(cin, input);
        cout << " playing music " << endl;
        PlaySound(TEXT("relaxing-birds-and-piano-music-137153.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

        getline(cin, input);
        cout<<"Music stopped."<<endl;
}

    if (x == 2)
    {
        
        PlaySound(TEXT("endless-by-prabajithk-118998.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

        string input;
        getline(cin, input);
        PlaySound(0, 0, 0);
       cout<<"Press any key to play the desired song."<<endl;

        getline(cin, input);
        cout << " playing music " << endl;
        PlaySound(TEXT("endless-by-prabajithk-118998.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

        getline(cin, input);
         cout<<"Music stopped."<<endl;
    }

    if (x == 3)
    {

        PlaySound(TEXT("inspirational-piano-141480.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

        string input;
        getline(cin, input);
        PlaySound(0, 0, 0);
        cout<<"Press any key to play the desired song."<<endl;

        getline(cin, input);
        cout << " playing music " << endl;
        PlaySound(TEXT("inspirational-piano-141480.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

        getline(cin, input);
         cout<<"Music stopped."<<endl;
    }

    if (x == 4)
    {
        
        PlaySound(TEXT("piano-moment-9835.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

        string input;
        getline(cin, input);
        PlaySound(0, 0, 0);
        cout<<"Press any key to play the desired song."<<endl;

        getline(cin, input);
        cout << " playing music " << endl;
        PlaySound(TEXT("piano-moment-9835.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

        getline(cin, input);
         cout<<"Music stopped."<<endl;
    }

    if (x == 5)
    {
    
        PlaySound(TEXT("slow-motion-121841.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

        string input;
        getline(cin, input);
        PlaySound(0, 0, 0);
        cout<<"Press any key to play the desird song."<<endl;

        getline(cin, input);
        cout << " playing music " << endl;
        PlaySound(TEXT("slow-motion-121841.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

        getline(cin, input);
         cout<<"Music stopped."<<endl;
    }
  

    }
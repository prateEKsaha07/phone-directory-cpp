#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class temp{
private:
    string name, address, description, search ,phone_no;
    fstream my_file;
public:
    void add_contact();
    void show_all_contacts();
    void search_contact();
} obj;

int main(){
    char choice;
    cout << "--------------------------------------------"<<endl;
    cout << " 1--> add contact "<<endl;
    cout << " 2--> show all contacts in the directory"<<endl;
    cout << " 3--> search for a contact "<<endl;
    cout << " 4--> exit"<<endl;
    cout << "--------------------------------------------"<<endl;
    cout <<" enter your choice : ";
    cin >> choice;

    switch (choice){
    case '1':
    cin.ignore();
    obj.add_contact();
    break;
    case '2':
    cin.ignore();
    obj.show_all_contacts();
    break;
    case '3':
    cin.ignore();
    obj.search_contact();
    break;
    case '4':
    cin.ignore();
    return 0;
    break;
    default:
    cout << "invalid option selected !!  ";
    break;
    }
    return 0;
}
void temp :: add_contact(){
    cout<<"Enter phone number : ";
    getline(cin,phone_no);
    cout<<"Enter full name : ";
    getline(cin,name);
    cout<<"enter the address : ";
    getline(cin,address);
    cout<<"enter the description : ";
    getline(cin,description);

    my_file.open("data.txt",ios::out | ios::app);
    my_file<<phone_no<<"*"<<name<<"*"<<address<<"*"<<description<<endl;
    my_file.close();
}
void temp :: show_all_contacts(){
    my_file.open("data.txt",ios :: in);

    getline(my_file,phone_no,',');
    getline(my_file,name,',');
    getline(my_file,address,',');
    getline(my_file,description,'\n');

    while(my_file.eof()){
        cout<<":: contact details ::"<<endl;
        cout<<"-----------------------------------";
        cout<<"persons name : "<<name<<endl;
        cout<<"phone number : "<<phone_no<<endl;
        cout<<"address details : "<<address<<endl;
        cout<<"description : "<<description<<endl;
        cout<<"-----------------------------------";

    getline(my_file,phone_no,',');
    getline(my_file,name,',');
    getline(my_file,address,',');
    getline(my_file,description,'\n');

    }

    my_file.close();
}
void temp :: search_contact(){
    cout<<"---------------------------------------"<<endl;
    cout<<"enter phone number : ";
    getline(cin,search);

    my_file.open("data.txt",ios :: in);
    
    getline(my_file,phone_no,',');
    getline(my_file,name,',');
    getline(my_file,address,',');
    getline(my_file,description,'\n');
    while(my_file.eof()){
        if(search==phone_no){
        cout<<":: contact details ::"<<endl;
        cout<<"-----------------------------------";
        cout<<"persons name : "<<name<<endl;
        cout<<"phone number : "<<phone_no<<endl;
        cout<<"address details : "<<address<<endl;
        cout<<"description : "<<description<<endl;
        cout<<"-----------------------------------";
        }
        getline(my_file,phone_no,',');
        getline(my_file,name,',');
        getline(my_file,address,',');
        getline(my_file,description,'\n')
    }
    
    my_file.close();
}


cout <<"whateve
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
int login(){
    int x,c=1;
    ifstream f;
    cout<<"FOOD DELIVERY SYSYTEM\n";
    cout<<"Press 1 for Customer \nPress 2 for Manager\n";
    cin>>x;
    system("CLS");
    if(x==1){
        return 1;
    }
    if(x==2){
        string buffer;
        f.open("txt/manager.txt");
        f>>buffer;
        f.close();
        while(c==1){
            string pwd;
            system("CLS");
            cout<<"Enter Password\n";
            cin>>pwd;
            if(buffer.compare(pwd)==0){
                cout<<"login successfull\n";
                cout << "\nPress enter to continue ...";
                        cin.get();
                        cin.get();
                return 2;
                c=0;
            }

            else{
                cout<<"incorrect password\n";
                cout<<"\nPress 1 to try again\nPress 2 to exit\n";
                cin>>x;
                if(x==2){
                    c=0;
                    return 0;
                }
            }
        }
    }
}

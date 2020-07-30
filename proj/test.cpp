#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int id,amt,loc,c=1,x;
    ofstream f;
      
    cout<<"enter id, amount and location
    while(c){
            cin>>id;
            cin>>amt;
            cin>>loc;
                f<<id<<" ";
                f<<amt<<" ";
                f<<loc<<endl;
        cout<<"want to add another item?"<<endl;
        cout<<"press 1 for yes, press 2 for no"<<endl;
        cin>>x;
        if(x==2){
            c=0;
        }
    }
    f.close();
}

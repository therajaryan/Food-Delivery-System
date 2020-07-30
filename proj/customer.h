#include <fstream>
#include <string>

using namespace std;
struct ordrlist
{
    int id;
    int count;
    int locn;
};


list < pair< int,ordrlist* > >listordr;
list < pair< int,int > > outstk;


ordrlist* getNode(int id, int count, int locn)
{

    ordrlist* temp = new(ordrlist);
    temp->id = id;
    temp->count = count;
    temp->locn = locn;
    return temp;

}

void ref_outstk( Tree *t1)
{
    list < pair< int,int > > :: iterator ref;
    vector < list <pair< int,int > > :: iterator > vect;
    for(ref = outstk.begin() ; ref != outstk.end(); ref++)
    {
        node* temp = t1->seek(ref->first);
        if(temp->Count < ref->second)
        {
            ref->second = ref->second - temp->Count;
        }
        else{
            vect.push_back(ref);
        }
    }
    while(vect.size())
    {
        ref = vect.back();
        vect.pop_back();
        outstk.erase(ref);
    }


}

bool sortinrev(const pair<int,int> &a,
               const pair<int,int> &b)
{
       return (a.first > b.first);
}

void order(Tree* t1)
{

    int id,amt,loc,c=1,x;
    ofstream f;
    f.open("txt/order.txt");


    while(c){
        system("CLS");
        cout<<"Welcome customer enter your order from the menu\n \n";
        cout<<"Menu\n";
        t1->menu();

		cout<<"\n\nLIST of Locations\n\n";
		cout<<"Sector 62 \t Code : 1\nSector 60 \t Code : 2\nSector 63 \t Code : 3\nSector 64 \t Code : 4\nSector 65 \t Code : 5\nSector 66 \t Code : 6\nSector 67 \t Code : 7\nSector 68 \t Code : 8\nSector 69 \t Code : 9\n";
		
        cout<<"\nenter id, count and location\n";
            cin>>id;
            cin>>amt;
            cin>>loc;
                f<<id<<" ";
                f<<amt<<" ";
                f<<loc<<endl;

            node* temp = t1->seek(id);
            if(temp->Count < amt)
            {
                outstk.push_back(make_pair(id,(amt-temp->Count)));
                ordrlist* node = getNode(id,amt,loc);
                listordr.push_back(make_pair( amt*temp->Cost , node ));
                t1->update(id,0,true);
            }
            else{
                ordrlist* node1 = getNode(id,amt,loc);
                listordr.push_back(make_pair( amt*temp->Cost , node1 ));

                t1->update(id,temp->Count - amt,true);
            }



        cout<<"\nwant to add another item?"<<endl;
        cout<<"press 1 for yes, press 2 for no"<<endl;
        cin>>x;
        if(x==2){
             // using modified sort() function to sort

            listordr.sort();
            c=0;
            system("CLS");
            cout<<"Order saved\n";
            cout << "\nPress enter to logout ...";
                        cin.get();
                        cin.get();
        }
    }
    f.close();
}


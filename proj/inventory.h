#include<list>
using namespace std;


list < pair< int,int > >:: iterator x1;

struct machine
{
    int key;
    int value;
    int unit;
}; 

machine e[] = {{1,(rand()%100)+20, 10}, {2,(rand()%100)+30, 20}, {3,(rand()%100)+40, 30}};

bool cmp(struct machine a, struct machine b)
{
    double r1 = (double)a.value / a.unit;
    double r2 = (double)b.value / b.unit;
    return r1 > r2;
}


double knapsack(int W, struct machine e[], int n)
{

    sort(e, e + n, cmp);



    int curvalue = 0;  // Current weight in knapsack
    double curunit=0;


    for (int i = 0; i < n; i++)
    {

        if (curvalue + e[i].value <= W)
        {
            curunit += e[i].unit;
            curvalue += e[i].value;
        }


        else
        {
            int remain = W - curvalue;
            curunit += e[i].unit * ((double) remain / e[i].value);
            break;
        }
    }


    return curunit;
}




void outStock(Tree* t1)
{
    int sum=0;
    for(x1 = outstk.begin(); x1!=outstk.end(); x1++)
    {

       cout<<"\ndefficient product id :"<<x1->first<<" and quantity : "<<x1->second<<endl;
       sum=sum+x1->second;    
   }
    outstk.clear();
    cout<<"\npress any key to produce\n";
    cin.get();
    cin.get();
    cout<<"\nItems Produced\n";
    
}


void inventory(Tree* t1)
{
    
    int b,k;
    while(true)
    {   
        system("clear");
        cout<<"Inventory\n \n";
        t1->inorder();
        cout<<"press 1: To produce more stock"<<endl;
        cout<<"press 2: For checking out of stock items"<<endl;
        cout<<"press 3: To exit inventory"<<endl;
        cin>>b;
        if(b==1)
        {
            int u,v,sum=0;
            
            while(true)
            {
                system("clear");
                cout<<"Current items in inventory\n";
                t1->inorder();
                cout<<"\nenter id of product\nand amount of product to add"<<endl;
                cin>>u;
                cin>>v;
                sum+=v;
                t1->update(u,v);
                
                cout<<"\nWant to produce more items?"<<endl;
                cout<<"Press 1 for yes, Press 0 for no\n";
                cin>>k;
                if(k==0)
                {
                    break;
                }

            }
            cout<<"\nItems Produced\n";
           // cout<<"\nelecticity used"<<" "<<knapsack(sum,e,3)<<" UNITS"<<endl;
            ref_outstk(t1);
            cout << "\nPress enter to continue ..."; 
            cin.get();
            cin.get();
        }


        else if(b==2)
        {
            if(outstk.size())
            {
                system("clear");
                cout<<"There are out of stock items"<<endl;
                outStock(t1);
                
            }
            else{
                system("clear");
                cout<<"No out of stock items\n";
            }

            cout << "\nPress enter to continue ..."; 
            cin.get();
            cin.get();
        
        }
        
        else if(b==3)
        {
            
            break;
        }


    }
}

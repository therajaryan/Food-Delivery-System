#include<bits/stdc++.h>
#include<fstream>
#include "tree.h"
#include "login.h"
#include "customer.h"
#include "dijk.h"
#include "inventory.h"

using namespace std;


int main()
{
	//load the inventory
	//load the inventory
	Tree t1;
	dijkstra(graph, 0);
	t1.load_data();
	list< pair<int , ordrlist*> > :: iterator itr;
	list< pair<int , ordrlist*> > :: iterator chk;
	pair<int , ordrlist*> ipair;

	//login interface
	// Customer = 1 Manager = 2 Exit = 0

	while(true)
	{
		system("CLS");
		int login_entity = login();

		// login part of the customer
		if(login_entity == 1)
		{

			order(&t1);
		}


		// login part of the manager
		else if(login_entity == 2)
		{
			int x;
			while(true)
		    {
		    	system("CLS");

		    	cout<<"Welcome Manager\n \n";
		    	cout<<"enter your choice"<<endl;
			    cout<<"1. Inventory"<<endl;
			    cout<<"2. Delivery"<<endl;
			    cout<<"0. Logout"<<endl;
			    cin>>x;
			    if(x==1)
			    {
			    	//inventry entry inventory(Tree* t1, list< pair<int , ordrlist*> > outstk);
			    	inventory(&t1);

			    }
			    else if(x==2)
			    {
			    	if(outstk.size())
			    	{
			    		system("CLS");
			    		cout<<"\nThe Stock is insufficient to Process Order"<<endl;
			    		cout<<"Please Update the Stock"<<endl;

			    		cout << "\nPress enter to continue ...";
    					cin.get();
    					cin.get();
			    		//calling outStock Funcn outStock(Tree *t1,list< pair<int , ordrlist*> > outstk )
			    		outStock(&t1);

			    		cout << "\nPress enter to continue ...";
    					cin.get();
    					cin.get();
			    	}

			    	// if appropriate stock available
			    	if(listordr.size())
			    	{
			    		int eff=0;
						int trad =0;
						int ttlcst=0;
			    		while(listordr.size())
				    	{
				    		system("CLS");
				    		ipair = listordr.back();
				    		mark42(ipair.second->locn);
				    		listordr.pop_back();
				    		//adding the cost once per route in efficent
				    		eff = eff + dist[ipair.second->locn];
				    		//adding same to the traditional
				    		trad = trad + dist[ipair.second->locn];

				    		ttlcst += ipair.first;
				    		//traversing the list for the locn common on route
				    		for(itr = listordr.begin(); itr!=listordr.end(); itr++)
					    	{
					    		if(marked[itr->second->locn])
					    		{
					    			marked[itr->second->locn] = false;
					    			//adding the traditional cost
					    			ttlcst += itr->first;
					    			trad = trad + dist[itr->second->locn];
					    			itr = listordr.erase(itr);

					    		}
					    	}

				    	}
				    	cout<<"If normal algo(Dijkstra) is used, total distance is"<<" "<<trad<<endl;
				    	cout<<"Efficent algo, total distance is"<<" "<<eff<<endl;
				    	cout<<"\nTotal Bill"<<" "<<ttlcst<<endl;
				    	cout<<"\nDelivery done"<<endl;
				    	//cout<<"press any key to continue"<<endl;
				    	//int c = getchar();
				    	cout << "\nPress enter to continue ...";
	    				cin.get();
	    				cin.get();
			    	}
			    	else{
			    		system("CLS");
			    		cout<<"There is no order placed"<<endl;
			    		cout << "\nPress enter to continue ...";
	    				cin.get();
	    				cin.get();
			    	}
			    }

			    //delivery over
			    else if(x==0)
			    {
			    	t1.save_data();
			    	break;
			    }
		    }


		}


	

	}

}




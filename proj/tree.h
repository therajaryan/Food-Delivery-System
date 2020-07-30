#include<fstream>
using namespace std;

struct node {
	int id;
	string Name;
	float Cost;
	int Count;
	node *left;
	node *right;
};

class Tree{
private:
	node * head;

	/* new Node */
	node * newnode(int x, string n, float c, int co)
	{
	    node *temp=new node();
	    temp->id=x;
	    temp->Name=n;
	    temp->Cost=c;
	    temp->Count=co;
	    temp->left=temp->right=NULL;
	    return temp;
	}

	/* InorderUtil */
	void inOrderUtil(struct node *root)
	{
		if(root != NULL)
		{
			inOrderUtil(root->left);
			cout<<"ID = "<<root->id<<"\n";
			cout<<"Name - "<<root->Name<<"\n";
			cout<<"Cost = "<<root->Cost<<"\n";
			cout<<"Count = "<<root->Count<<"\n \n";
			inOrderUtil(root->right);
		}
	}

	void saveUtil(struct node *root,ofstream &f)
	{
		if(root != NULL)
		{
			saveUtil(root->left,f);
			f<<root->id<<endl;
			f<<root->Name<<endl;
			f<<root->Cost<<endl;
			f<<root->Count<<endl;
			saveUtil(root->right,f);
		}
	}

	void menuUtil(struct node *root)
	{
		if(root != NULL)
		{
			menuUtil(root->left);
			cout<<"ID = "<<root->id<<"  ";
			cout<<"Name - "<<root->Name<<"  ";
			cout<<"Cost = "<<root->Cost<<"\n";
			menuUtil(root->right);
		}

	}

	/* seekUtil Util */
	node * seekUtil(node* parent, int n)
	{
	    if(parent->id==n)
	        return parent;
	    else if (parent->left==NULL && parent->right==NULL)
	        return NULL;
	    else if(parent->id<n)
	        return seekUtil(parent->right,n);
	    else if(parent->id>n)
	        return seekUtil(parent->left,n);
	}

	/* UpdateUtil Util */
	void updateUtil(node * root, int ir,int val,bool inplace)
	{
	    root=seekUtil(root, ir);
	    if(root  && inplace)
	        root->Count = val;
	    else if(root && !inplace)
	    {
	    	root->Count += val;
	    }
	}

	/* height Util */

	int heightUtil(node* node)
	{
	   if (node==NULL)
	       return -1;
	   else
	   {
	       int lDepth = heightUtil(node->left);
	       int rDepth = heightUtil(node->right);
	       if (lDepth > rDepth)
	           return(lDepth+1);
	       else return(rDepth+1);
	   }
	}

	/* insert Util */

	node * left( node * z)
		{
		    node * y=z->right;
		    node * t2=y->left;

		    y->left=z;
		    z->right=t2;
		    return y;
		}

	node *right (node *z)
		{
		    node *y=z->left;
		    node *t2=y->right;

		     y->right=z;
		     z->left=t2;
		     return y;
		}


	node * insertUtil(node* temp,int x,string n,float co,int cu)
	{
	    node *root=temp;
	    vector<char>v;
	    stack<node *>s;
	    node* par=NULL;

	    while(temp)
	    {

            s.push(temp);
            par=temp;

		    if((temp->id) > x)
		    {
		        v.push_back('l');
		        temp=temp->left;
		    }

	     	else if((temp->id) <x)
	     	{
	         	v.push_back('r');
	         	temp=temp->right;
	     	}
		}


		if(par->id >x)
		{
		    par->left=newnode(x,n,co,cu);
		}

		else
		{
		    par->right=newnode(x,n,co,cu);
		}


		int c=v.size();

		while(!s.empty())
		{
		    node * temp2=s.top();
		    s.pop();
		    --c;
		    int ld=0,rd=0;
		    ld=heightUtil(temp2->left);
		    rd=heightUtil(temp2->right);
		    ld=ld-rd;

		    if(abs(ld)>1)
		    {
		      	if(v[c]=='l')
		      	{
		          	if(x < temp2->left->id)//left left case
		          	{
		             	temp2= right(temp2);
		          	}
		          	else {
		            	temp2->left =  left(temp2->left); // left right
		           		temp2= right(temp2);
		          	}
		      	}

		      	else{
		            if(x >temp2->right->id)
		            {//right right
		         	temp2=left(temp2);
		      		}

		      		else{
		        	temp2->right=right(temp2->right); //right left
		        	temp2=left(temp2);
		      		}
		    	}

			    if(s.empty())
			    {
			        return temp2;
			    }

			    else
			    {
			        node *parent=s.top();
			        if(parent->id > temp2->id)
			        {
			            parent->left=temp2;
			        }
			        else{
			            parent->right=temp2;
			        }
			        return root;
			    }
			}

			else
			{
			    if(s.empty())
			    {
			        return temp2;
			    }
			}

		}


	}

/*////////*/

public:
	Tree()
	{
		head = NULL;
	}

    /* Inorder Print */

	void inorder()
	{
		inOrderUtil(head);
	}

	void save_data()
	{
		ofstream f;
		f.open("txt/data.txt");
		saveUtil(head,f);
		f.close();
	}

	void menu()
	{
		menuUtil(head);
	}

	/*  Searching the Node */
	node * seek(int n)
	{
	   return seekUtil(head,n);
	}

	/* Update Node */

	void update(int ir,int val ,bool inplace = false)
	{
	    updateUtil(head,ir,val,inplace);
	}

	/* Height of Tree */

	int height()
	{
		return heightUtil(head);
	}


	/* insert New Node */

	void insert(int x,string n,float co,int cu)
	{
		if(head)
		{
			head = insertUtil(head,x,n,co,cu);
		}
		else
		{
			head = newnode(x,n,co,cu);
		}
	}



	//save the  data in txt file

	void load_data()
	{
		int id = 0;
    	string Name = "";
    	float Cost = 0;
    	int Count = 0;

    	ifstream infile;
    	infile.open ("txt/data.txt");


    	while(infile >> id >> Name >> Cost >> Count)
    	{

        	this->insert(id,Name,Cost,Count);
    	}

    	infile.close();
	}

};



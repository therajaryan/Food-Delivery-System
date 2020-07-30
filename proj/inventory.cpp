using namespace std;



struct emp
{
    int key;
    int value;
    int unit;
};
emp e[] = {{1,(rand()%100)+20, 10}, {2,(rand()%100)+30, 20}, {3,(rand()%100)+40, 30}};

bool cmp(struct emp a, struct emp b)
{
    double r1 = (double)a.value / a.unit;
    double r2 = (double)b.value / b.unit;
    return r1 > r2;
}


double knapsack(int W, struct emp e[], int n)
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

//int main()
//{
//    cout<<knapsack(200,e,3)<<endl;
//    return 0;
//}


void outStock(Tree* t1, list< pair<int , ordrlist*> > outstk)
{
	
}


void inventory(Tree* t1, list< pair<int , ordrlist*> > outstk)
{

}

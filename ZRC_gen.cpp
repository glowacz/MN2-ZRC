#include <bits/stdc++.h>

using namespace std;

const int A = 100, D = 5e6, n = 5e5, d = 50;
vector<int> ciA[n+3], vicA[n+3];
bool odw[n+1];

int main()
{
    srand(time(0));
    ofstream out;

    out.open("ciA.txt");
    //out <<"ciA = [\n";
    //out <<"[\n";
    for(int i=1; i<=n; i++)
    {
        ciA[i].push_back(i);
        odw[i] = 1;
        for(int j=0; j<d-1; j++)
        {
            int ind = rand() % n + 1;
            while( odw[ind] )
                ind = rand() % n + 1;
            ciA[i].push_back( ind );
            odw[ind] = 1;
        }
        sort(ciA[i].begin(), ciA[i].end());
        for( auto a : ciA[i] )
            out << a <<" ";
        //out <<";\n";
        out <<"\n";

        for( auto a : ciA[i] )
            odw[a] = 0;
    }
    //out <<"];\n";
    out.close();

    out.open("vicA.txt");
    //out <<"vicA = [\n";
    //out <<"[\n";
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<d; j++)
        {
            if( ciA[i][j] == i)
            {
                int ind = rand()%(2*D) - D;
                if( ind < 0 )
                    ind -= d*A + 5;
                else
                    ind += d*A + 5;
                vicA[i].push_back( ind );
            }
                
            else
                vicA[i].push_back( rand()%(2*A) - A );
        }
        for( auto a : vicA[i] )
            out << a <<" ";
        //out <<";\n";
        out <<"\n";
    }
    //out <<"];\n";
    out.close();

    out.open("b.txt");
    //out <<"b = ["; 
    //out <<"["; 
    for(int i=1; i<=n; i++)
    {
        out << rand()%(2*D) - D <<"\n";
    }
    //out <<"];";
    out.close();

    return 0;
}
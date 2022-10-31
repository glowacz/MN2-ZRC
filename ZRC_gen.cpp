#include <bits/stdc++.h>

using namespace std;

int main()
{
    srand(time(0));

    int A = 100, D = 5e6;
    int n = 5, d = 3;
    vector<int> ciA[n+3], vicA[n+3];

    cout <<"[\n";
    for(int i=1; i<=n; i++)
    {
        
        ciA[i].push_back(i);
        for(int j=1; j<d; j++)
        {
            ciA[i].push_back(rand()%n + 1);
            //cout <<rand()%(2 * A) - A << " ";
        }
        sort(ciA[i].begin(), ciA[i].end());
        for( auto a : ciA[i] )
            cout << a <<" ";
        cout <<";\n";
    }
    cout <<"]\n";

    cout <<"[\n";
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<d; j++)
        {
            if( ciA[i][j] == i)
                vicA[i].push_back( rand()%(2*D) - D );
            else
                vicA[i].push_back( rand()%(2*A) - A );
            //cout <<rand()%(2 * A) - A << " ";
        }
        for( auto a : vicA[i] )
            cout << a <<" ";
        cout <<";\n";
    }
    cout <<"]\n";
    return 0;
}
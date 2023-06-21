#include <bits/stdc++.h>

using namespace std;

int max(int a, int b)
{
    return (a > b)? a : b;
}

int naiveRecursion(int p[], int n)
{
    if (n==0)
        return 0;
    int q = -99999999;
    for(int i=1; i<=n; i++)
    {
        q=max(q,p[i-1]+naiveRecursion(p,n-i));
    }
    return q;
}

int tabulation(int p[],int n)
{
    int r[n+1];
    r[0]=0;
    int i,j;
    for(j=1; j<=n; j++)
    {
        int q=-9999999;
        for(i=1; i<=j; i++)
        {
            q=max(q,p[i-1]+r[j-i]);
            //cout << q <<endl;
        }
        r[j]=q;

    }
    for(j=1; j<=n; j++)
    {
        for(int k=1; k<=j; k++)
        {
            if(r[n]==r[j]+r[k])
            {
                cout << k << " pieces together " << r[k] << " taka" << endl;
                cout << j << " pieces together " << r[j] << " taka" << endl;

            }
        }

    }
    return r[n];
}

int main()
{
    int n;
    cin >> n;
    int p[n];
    for(int i=0; i<n; i++)
    {
        cin >> p[i];
    }
    int inc = naiveRecursion(p, n);
    cout <<"income: "<<inc<<" taka" << endl;

    tabulation(p, n);
    //cout <<"income: "<<inc1<<" taka";

    return 0;
}



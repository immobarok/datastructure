#include <iostream>
using namespace std;


bool recursive(int A[], int n, int sum)
{

    if (sum == 0)
        return true;
    if (n == 0)
        return false;

    if (A[n - 1] > sum)
        return recursive(A, n - 1, sum);

    return recursive(A, n - 1, sum)
           || recursive(A, n - 1, sum - A[n - 1]);
}


int tabulation(int A[], int n, int sum)
{

    int subset[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        subset[i][0] = 0;

    for (int j = 1; j <= sum; j++)
        subset[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        int value;
        for (int j = 1; j <= sum; j++)
        {
            int v = A[i - 1];
            if (v <= j)
            {
                if(v+subset[i-1][j-v]>subset[i-1][j])
                {
                    subset[i][j] = v+subset[i - 1][j-v];
                    value = subset[i][j]-subset[i - 1][j-v];
                    //cout << value << endl;
                }
                else
                {
                    subset[i][j] = subset[i-1][j];
                    value = subset[i][j];
                    //cout << value;
                }

            }
            else
            {
                subset[i][j] = subset[i-1][j];
            }
        }

        if(value!=sum&& value!=A[0])
            cout << value << " + ";
    }

    return subset[n][sum];
}


int main()
{
    int n;
    cin >> n;
    int A[n];
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
    }
    int X;
    cin >> X;
    if (recursive(A, n, X) == true)
        cout << X <<" is a subset sum" << endl;
    else
        cout << X <<" is not a subset sum" << endl;

    int sum = tabulation(A, n, X);
    cout << " = " << sum;
    return 0;
}




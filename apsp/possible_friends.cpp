// SPOJ: Possible Friends

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        string row;
        cin >> row;
        int N = row.length();

        vector<string> grid(N);
        grid[0] = row;
        for (int i = 1; i < N; i++)
        {
            cin >> grid[i];
        }

        int maxi = 0;
        int id = 0;

        for (int i = 0; i < N; i++)
        {
            int count = 0;

            for (int j = 0; j < N; j++)
            {
                if (i == j)
                    continue;

                if (grid[i][j] == 'N')
                {
                    bool found = false;

                    for (int k = 0; k < N; k++)
                    {
                        if (grid[i][k] == 'Y' && grid[k][j] == 'Y')
                        {
                            found = true;
                            break;
                        }
                    }

                    if (found)
                        count++;
                }
            }

            if (count > maxi)
            {
                maxi = count;
                id = i;
            }
        }

        cout << id << " " << maxi << endl;
    }
    return 0;
}
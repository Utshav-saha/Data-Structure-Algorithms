#include <bits/stdc++.h>
using namespace std;

int global_alignment(int m, int n, string &s1, string &s2,int match, int gap, int mismatch, vector<vector<int>> &arr, vector<vector<int>> &soln)
{
    soln[0][0] = -1;

    for (int i = 0; i <= m; i++)
    {
        arr[i][0] = i * gap;
        soln[i][0] = 1;
    }

    for (int j = 0; j <= n; j++)
    {
        arr[0][j] = j * gap;
        soln[0][j] = 2;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            int cost1;
            if (s1[i - 1] == s2[j - 1])
            {
                cost1 = match + arr[i - 1][j - 1];
            }
            else cost1 = mismatch + arr[i - 1][j - 1];

            int cost2 = gap + arr[i - 1][j];
            int cost3 = gap + arr[i][j - 1];

            arr[i][j] = max({cost1, cost2, cost3});

            if(arr[i][j] == cost1) soln[i][j] = 0;
            if(arr[i][j] == cost2) soln[i][j] = 1;
            if(arr[i][j] == cost3) soln[i][j] = 2;

        }
    }

    return arr[m][n];
}


void print(string &s1, string &s2,vector<vector<int>> &soln){

    string ans1;
    string ans2;

    int i = s1.size();
    int j = s2.size();

    while( i>0 || j>0){
        if(soln[i][j] == 0){
            ans1 += s1[i-1];
            ans2 += s2[j-1];
            i--;
            j--;
        }

        else if(soln[i][j] == 1){
            ans1 += s1[i-1];
            ans2 += "-";
            i--;
            
        }

        else if(soln[i][j] == 2){
            ans1 += "-";
            ans2 += s2[j-1];
            j--;
            
        }
        
    }

    reverse(ans1.begin(), ans1.end());
    reverse(ans2.begin(), ans2.end());

    cout << ans1 << endl;
    cout << ans2 << endl;

}
int main()
{

    int m, n, match, mismatch, gap;
    string s1;
    string s2;

    cout << "Enter first sequence: " << endl;
    cin >> s1;
    cout << "Enter second sequence: " << endl;
    cin >> s2;

    m = s1.length();
    n = s2.length();

    cout << "Enter match score: " << endl;
    cin >> match;

    cout << "Enter mismatch penalty: " << endl;
    cin >> mismatch;

    cout << "Enter gap penalty: " << endl;
    cin >> gap;



    vector<vector<int>> arr(m + 1, vector<int>(n + 1));
    vector<vector<int>> soln(m + 1, vector<int>(n + 1));

    int ans = global_alignment(m, n , s1, s2,match, gap, mismatch, arr, soln);
    
    cout << "Global Alingment: " << endl;
    print(s1, s2, soln);

    cout << "Maximum Score: " << ans << endl;
}
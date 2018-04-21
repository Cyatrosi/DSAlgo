#include<bits/stdc++.h>
using namespace std;
int ansp,anst;
/* mat:  Pointer to the starting of mXn matrix
   i, j: Current position of the robot (For the first call use 0,0)
   m, n: Dimentions of given the matrix
   pi:   Next index to be filed in path array
   *path[0..pi-1]: The path traversed by robot till now (Array to hold the
                  path need to have space for at least m+n elements) */
void printAllPathsUtil(int *time,int *mat,int *t, int i, int j, int m, int n, int *path, int pi)
{
    // Reached the bottom of the matrix so we are left with
    // only option to move right
    if (i == m - 1)
    {
        for (int k = j; k < n; k++)
            {
                path[pi + k - j] = *((mat + i*n) + k);
                time[pi + k - j] = *((t + i*n) + k);
            }
        int p=0,s = 0;
        for (int l = 0; l < pi + n - j; l++)
            {p+=path[l];s+=time[l];}
        if(p<ansp)
        {
            ansp = p;
            anst = s;
        }
        else if(ansp == p)
        {
            anst = min(anst,s);
        }
        return;
    }

    // Reached the right corner of the matrix we are left with
    // only the downward movement.
    if (j == n - 1)
    {
        for (int k = i; k < m; k++)
            {
                path[pi + k - i] = *((mat + k*n) + j);
                time[pi + k - i] = *((t + k*n) + j);
            }
        int p = 0,s = 0;
        for (int l = 0; l < pi + m - i; l++)
            {p+=path[l];s+=time[l];}
            if(p<ansp)
        {
            ansp = p;
            anst = s;
        }
        else if(ansp == p)
        {
            anst = min(anst,s);
        }
        return;
    }

    // Add the current cell to the path being generated
    path[pi] = *((mat + i*n) + j);
    time[pi] = *((t + i*n) + j);

    // Print all the paths that are possible after moving down
    printAllPathsUtil(time,mat,t, i+1, j, m, n, path, pi + 1);

    // Print all the paths that are possible after moving right
    printAllPathsUtil(time,mat,t, i, j+1, m, n, path, pi + 1);

    // Print all the paths that are possible after moving diagonal
    // printAllPathsUtil(mat, i+1, j+1, m, n, path, pi + 1);
}

// The main function that prints all paths from top left to bottom right
// in a matrix 'mat' of size mXn
void printAllPaths(int *mat,int *t, int m, int n)
{
    int *path = new int[m+n];
    int *time = new int[m+n];
    printAllPathsUtil(time,mat,t, 0, 0, m, n, path, 0);
}

// Driver program to test abve functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,i,j;
        cin>>n>>m;
    int mat[n][m],t[n][m];
    for(i=0;i<n;++i)
        for(j=0;j<m;++j)
            cin>>mat[i][j];
    for(i=0;i<n;++i)
        for(j=0;j<m;++j)
            cin>>t[i][j];
    ansp = 10000;
    anst = 10000;
    printAllPaths(*mat,*t, n, m);
    cout<<ansp<<" "<<anst<<endl;
    }
    return 0;
}

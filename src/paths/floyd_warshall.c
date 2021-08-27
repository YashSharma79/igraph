'#'define INF 9999999

using namespace std;

int main()
{
    int n,m,i,x,y,r,a,b,j,k,q;
    cin>>n>>m;
    int adj[n][n];

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            adj[i][j]=INF;
        }
    }

    for(i=0;i<n;i++) {
        adj[i][i]=0;
    }

    int floyd[n][n];

    for(i=0;i<m;i++)
    {
        cin>>x>>y>>r;
        adj[x-1][y-1]=r;
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            floyd[i][j]=adj[i][j];
        }
    }

    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[k][j]);
            }
        }
    }

    cin>>q;

    while(q--)
    {
        cin>>a>>b;
        int ans=floyd[a-1][b-1];
        if(ans!=INF)
            cout<<ans<<endl;
        else
            cout<<"-1\n";
    }
    return 0;
}

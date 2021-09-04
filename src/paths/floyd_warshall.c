
using namespace std;

int igraph_shortest_paths_floyd_warshall(const igraph_t *graph,
                                       igraph_matrix_t *res,
                                       const igraph_vs_t from,
                                       const igraph_vs_t to,
                                       const igraph_vector_t *weights,
                                       igraph_neimode_t mode)
{

    // replace n with number_of_nodes
    long int no_of_nodes = igraph_vcount(graph);
    igraph_real_t my_infinity = IGRAPH_INFINITY;

    long int i, j, k;

    igraph_matrix_t adj;
    igraph_matrix_init(&adj,no_of_nodes, no_of_nodes);

    // array of minimum distances initialized to ∞ (infinity)
    for (i = 0; i < no_of_nodes; i++)
    {
        for (j = 0; j < no_of_nodes; j++)
        {
            igraph_matrix_t[i][j] = my_infinity;
        }
    }

    // distance to the same node = 0
    for (i = 0; i < no_of_nodes; i++)
    {
        igraph_matrix_t[i][i] = 0;
    }

    igraph_matrix_t floyd;
    igraph_matrix_init(&floyd, no_of_nodes, no_of_nodes);

    // assign weight of i, j as shortest distance
    for (i = 0; i < no_of_nodes; i++)
    {
        for (j = 0; j < no_of_nodes; j++)
        {
            MATRIX(*floyd, i, j) = MATRIX(*adj, i, j)
        }
    }

    for (k = 0; k < no_of_nodes; k++)
    {
        for (i = 0; i < no_of_nodes; i++)
        {
            for (j = 0; j < no_of_nodes; j++)
            {
                MATRIX(*floyd, i, j) = min(MATRIX(*floyd, i, j), MATRIX(*floyd, i, k) + MATRIX(*floyd, k, j));
            }
        }
    }


    /* For testing only
    cin >> q;
    while (q--)
    {
        cin >> a >> b;
        int ans = floyd[a - 1][b - 1];
        if (ans != INF)
            cout << ans << endl;
        else
            cout << "-1\n";
    }
    */
    return 0;
}
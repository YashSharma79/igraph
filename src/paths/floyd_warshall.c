#include "igraph_paths.h"

#include "igraph_adjlist.h"
#include "igraph_dqueue.h"
#include "igraph_interface.h"
#include "igraph_memory.h"
#include "igraph_stack.h"

#include "core/indheap.h"
#include "core/interruption.h"

#include <string.h>

int igraph_shortest_paths_floyd_warshall(const igraph_t *graph,
                                       const igraph_vector_t *weights)
{

    // replace n with number_of_nodes
    long int no_of_nodes = igraph_vcount(graph);
    igraph_real_t my_infinity = IGRAPH_INFINITY;

    long int i, j, k;

    igraph_matrix_t floyd;
    igraph_matrix_init(&floyd, no_of_nodes, no_of_nodes);

    // array of minimum distances initialized to ∞ (infinity)
    for (i = 0; i < no_of_nodes; i++)
    {
        for (j = 0; j < no_of_nodes; j++)
        {
            MATRIX(floyd, i, j) = my_infinity;
        }
    }

    // distance to the same node = 0
    for (i = 0; i < no_of_nodes; i++)
    {
        MATRIX(floyd, i, j) = 0;
    }

    // assign weight of i, j as shortest distance
    for (i = 0; i < no_of_nodes; i++)
    {
        for (j = 0; j < no_of_nodes; j++)
        {
            MATRIX(floyd, i, j) = VECTOR(*weights) [j];
        }
    }

    for (k = 0; k < no_of_nodes; k++)
    {
        for (i = 0; i < no_of_nodes; i++)
        {
            for (j = 0; j < no_of_nodes; j++)
            {
                if (MATRIX(floyd, i, k) + MATRIX(floyd, k, j) < MATRIX(floyd, i, j))
                {
                    MATRIX(floyd, i, j) = MATRIX(floyd, i, k) + MATRIX(floyd, k, j);
                }
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

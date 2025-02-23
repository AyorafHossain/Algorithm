#include <stdio.h>


int a[10][10], n, indegree[10];

void in_degree()
{
    int i, j, sum;
    // Calculate the in-degree for each vertex
    for (j = 0; j < n; j++)
    {
        sum = 0;
        for (i = 0; i < n; i++)
        {
            sum = sum + a[i][j];
        }
        indegree[j] = sum;
    }
}

void topological_sort()
{
    int i, u, v, result[10], s[10], top = -1, k = 0;
    in_degree();  // Calculate in-degrees for all vertices

    // Initialize the stack with vertices having zero in-degree
    for (i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            s[++top] = i;
        }
    }


    while (top != -1)
    {
        u = s[top--];  // Pop the vertex from the stack
        result[k++] = u;  // Add it to the result

        // Visit all adjacent vertices of u
        for (v = 0; v < n; v++)
        {
            if (a[u][v] == 1)    // There is an edge from u to v
            {
                indegree[v]--;  // Decrease the in-degree of v
                if (indegree[v] == 0)    // If in-degree becomes 0, add it to the stack
                {
                    s[++top] = v;
                }
            }
        }
    }

    // Check if all vertices are processed (if not, the graph has a cycle)
    if (k != n)
    {
        printf("Cycle detected! Topological sort is not possible.\n");
        return;
    }

    // Print the topological order
    printf("Topological sort: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main()
{
    int i, j;

    // Input the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);  // Correcting the scanf format for matrix input
        }
    }

    // Perform topological sort
    topological_sort();

    return 0;
}

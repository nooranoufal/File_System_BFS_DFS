
#include <stdio.h>

#define MAX 5

int graph[MAX][MAX] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 0, 1},
    {0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0}
};

char *files[MAX] = {
    "Root", "Documents", "Downloads",
    "Notes.txt", "Photo.jpg"
};

int visited[MAX];

/* Breadth-First Search */
void BFS(int start, int target)
{
    int queue[MAX], front = 0, rear = 0;
    int found = 0;

    for (int i = 0; i < MAX; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("\nBFS Traversal: ");

    while (front < rear)
    {
        int node = queue[front++];
        printf("%s ", files[node]);

        if (node == target)
            found = 1;

        for (int i = 0; i < MAX; i++)
        {
            if (graph[node][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    if (found)
        printf("\nBFS: File/Directory found.");
    else
        printf("\nBFS: File/Directory not found.");
}

/* Depth-First Search */
void DFS(int node, int target, int *found)
{
    visited[node] = 1;
    printf("%s ", files[node]);

    if (node == target)
        *found = 1;

    for (int i = 0; i < MAX; i++)
    {
        if (graph[node][i] == 1 && !visited[i])
            DFS(i, target, found);
    }
}

int main()
{
    int start, target, found = 0;

    printf("File System Representation\n");
    printf("0 - Root\n");
    printf("1 - Documents\n");
    printf("2 - Downloads\n");
    printf("3 - Notes.txt\n");
    printf("4 - Photo.jpg\n");

    printf("\nEnter starting node (0-4): ");
    scanf("%d", &start);

    printf("Enter file/directory to search (0-4): ");
    scanf("%d", &target);

    if (start < 0 || start >= MAX ||
        target < 0 || target >= MAX)
    {
        printf("Invalid node number.\n");
        return 0;
    }

    BFS(start, target);

    for (int i = 0; i < MAX; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");
    DFS(start, target, &found);

    if (found)
        printf("\nDFS: File/Directory found.\n");
    else
        printf("\nDFS: File/Directory not found.\n");

    return 0;
}

#include "Dialog.h"

int main() {
    const char *messages[] = {"0. Quit", "1. Add Vertex", "2. Add Edge", "3. Find Path", "4. Find Shortest Path", "5. Delete Vertex", "6. Delete Edge", "7. Show", "8. Show Skeleton"};
    const int messageSize = sizeof(messages) / sizeof(messages[0]);
    int (*functions[])(Matrix *) = {NULL, D_AddVertex, D_AddEdge, D_FindPath, D_FindShortestPath, D_DeleteVertex, D_DeleteEdge, D_Show, D_ShowSkeleton};
    Matrix *matrix = getMatrix();
    int actionIndex;
    while ((actionIndex = dialog(messages, messageSize))) {
        if (!functions[actionIndex](matrix)) break;
    }
    puts("That's all. Bye!\n");
    destroyMatrix(matrix);
    return 0;
}

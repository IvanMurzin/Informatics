#include <stdio.h>
#include <stdlib.h>
#include "GraphGenerator.h"

#define DOT_HEADER "strict graph {\n"
#define DOT_FOOTER "}"
#define DOT_VERTEX " \"(%d;%d)\";\n"
#define DOT_EDGE " \"(%d;%d)\" -- \"(%d;%d)\";\n"

int createPngGraph(const Matrix *matrix) {
    if (matrix == NULL || matrix->containers == NULL) return 1;
    FILE *file = fopen("../output/graph.dot", "w");
    if (file == NULL) return 1;
    fprintf(file, DOT_HEADER);
    for (int i = 0; i < matrix->size; ++i) {
        Container container = matrix->containers[i];
        fprintf(file, DOT_VERTEX, container.vertex.x, container.vertex.y);
        for (int j = 0; j < matrix->size; ++j) {
            if (container.data[j] == 1) {
                fprintf(file, DOT_EDGE, container.vertex.x, container.vertex.y, matrix->containers[j].vertex.x, matrix->containers[j].vertex.y);
            }
        }
    }
    fprintf(file, DOT_FOOTER);
    fclose(file);
    system("dot -Tpng -O ../output/graph.dot");
    return 0;
}

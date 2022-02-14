struct matrix {
    int columnSize;
    int rowSize;
    int **data;
};

typedef struct matrix matrix;

int insertRow(matrix *a,  int index);

int deleteRow(matrix *a, int index);

int insertColumn(matrix *a, int index);

int deleteColumn(matrix *a, int index);

void printMatrix(matrix *a);

void destroyData(matrix *a);

void destroy(matrix *a);

int multiplyMatrix(matrix *a, matrix *b);

matrix *getMatrixFromStd();

matrix *generateMatrix(int n, int m);

int writeToBinaryFile(const char *filePath, matrix *a);

matrix *readFromBinaryFile(const char *filePath);

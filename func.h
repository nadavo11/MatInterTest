
#define ROWS 10
#define COLS 10

#ifndef UNTITLED11_FUNC_H
#define UNTITLED11_FUNC_H
/************************************************************************
 *                                                                      *
 *                    declarations & helpers                            *
 *                                                                      *
 ********************************************************************** */
int mat1[ROWS][COLS], mat2[ROWS][COLS], resmat[ROWS][COLS], mau[ROWS][COLS];

void printMatrix(int matrix[][COLS]);
void printMenu();
void createMatrices(int offset1,int offset2);
void addAndPrintMats();
void computeAndPrintMaximalTrace();
void printCombinedMaxMatrix();
void swapDiagonal(int (* matt)[COLS]);
void sortMatrixLine(int (* matt)[COLS],int line) ;


#define ROWS 10
#define COLS 10
/************************************************************************
 *                                                                      *
 *                    declarations & helpers                            *
 *                                                                      *
 ********************************************************************** */
int mat1[ROWS][COLS], mat2[ROWS][COLS], resmat[ROWS][COLS];

void printMatrix(int matrix[][COLS]) {

    printf("[\n");
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            printf("%d, ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("]\n"
           "");
}

void printMenu() {
    printf(" --------------------- Menu --------------------------------------------------------\n"
           " -----------------------------------------------------------------------------------\n");
    printf("1) Create two 10x10 matrices Mat1,Mat2 using the next expression:\n for i,j Mat1[i][j] - (offset + i*10 + j) % 100\n");
    printf("2) Compute and show the matrix Mat1 + Mat2\n");
    printf("3) Compute and show the maximal Trace between matrices Matt and Mat1\n");
    printf("4) Compute and show the combined maximal matrix between Matu and Matt\n");
    printf("5) Swap between primary diagonal and the secondary diagonal according to user choice\n");
    printf("6) Sort a given line in a given matrix\n");
    printf("7) Show a given Matrix\n");
    printf("8) Show menu\n");
    printf("9) Exit\n");
}

/************************************************************************
 *                                                                      *
 *                    1 - create matz with offsets                      *
 *                                                                      *
 ********************************************************************** */
void createMatrices(int offset1,int offset2) {
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            mat1[i][j] = (offset1 + i*10 + j) % 100;
            mat2[i][j] = (offset2 + i*10 + j) % 100;
            resmat[i][j] = mat1[i][j] + mat2[i][j];
            //mat4[i][j] = (offset + i*10 + j) % 100;
        }
    }
}

/************************************************************************
 *                                                                      *
 *               2 - Compute and show the materix Mat1+Mat2             *
 *                                                                      *
 ********************************************************************** */

void addAndPrintMats() {
    int i, j;
    int result[ROWS][COLS];
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    printf("resMat = Mat1+Mat2 =\n");
    printMatrix(result);
}
/************************************************************************
 *                                                                      *
 *            3 - Compute and show the max trace of Mat1 & Mat2         *
 *                                                                      *
 ********************************************************************** */
void computeAndPrintMaximalTrace() {
    int i, j;
    int trace1 =0;
    int trace2 =0;
    //add all of the diagonal ellements
    for(i=0; i<ROWS; i++) {
        trace1 += mat1[i][i];
        trace2 += mat2[i][i];
    }

    trace1>trace2 ? printf("mat1 has the maximal Trace value: %d\n",trace1) : printf("mat2 has the maximal Trace value: %d\n",trace2);

}
/************************************************************************
 *                                                                      *
 *            4 - Compute and show the max matrix of Mat1 & Mat2        *
 *                                                                      *
 ********************************************************************** */

void printCombinedMaxMatrix() {
    int i, j;
    int result[ROWS][COLS];
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            result[i][j] = mat1[i][j] > mat2[i][j] ? mat1[i][j] : mat2[i][j];
        }
    }
    printf("\nmaxMat = max(Mat1,Mat2) =\n");
    printMatrix(result);
}

/************************************************************************
 *                                                                      *
 *            5 - Swap primary & secondary diagonals                    *
 *                                                                      *
 ********************************************************************** */
void swapDiagonal(int (* matt)[COLS]) {

    int i;
    //for each diagonal entry
    for(i=0; i<ROWS; i++) {

        //switch primary with secondary
        int temp = matt[i][i];
        matt[i][i] = matt[i][COLS-i-1];
        matt[i][COLS-i-1] = temp;


    }
    printMatrix(matt);
}


void sortMatrixLine(int (* matt)[COLS],int line) {
    int i, j;

    //bubble sort
    for(i=0; i<COLS; i++) {
        for(j=i+1; j<COLS; j++) {
            if(matt[line][j] < matt[line][i]) {
                //switch entries
                int temp = matt[line][i];
                matt[line][i] = matt[line][j];
                matt[line][j] = temp;
            }
        }
    }
    printMatrix(matt);
}

#endif //UNTITLED11_FUNC_H



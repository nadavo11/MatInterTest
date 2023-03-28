#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10
/************************************************************************
 *                                                                      *
 *                    declarations & helpers                            *
 *                                                                      *
 ********************************************************************** */
int mat1[ROWS][COLS], mat2[ROWS][COLS], resmat[ROWS][COLS], mau[ROWS][COLS];

void printMatrix(int matrix[][COLS]) {
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            printf("%d, ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printMenu() {
    printf(" --------------------- Menu --------------------------------------------------------\n"
           " -----------------------------------------------------------------------------------\n");
    printf("1) Create two 10x10 matrices Mat1,Mat2 using the next expression: for i,j Mat1[i][j] - (offset + i*10 + j) % 100\n");
    printf("2) Compute and show the matrix Mat1 + Mat2\n");
    printf("3) Compute and show the maximal Trace between matrices Matt and Mat1\n");
    printf("4) Compute and show the combined maximal matrix between Matu and Matt\n");
    printf("5) Swap between primary diagonal and the secondary diagonal according to user choice\n");
    printf("6) Sort a given line in a given matrix\n");
    printf("7) Show a given Matrix\n");
    printf("8) Show menu\n");
    printf("9) Exit");
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
    printf("\nMats created!\n");
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
    printf("\nresMat = Mat1+Mat2 =\n");
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

    trace1>trace2 ? printf("\nmat1 has the maximal Trace value: %d\n",trace1) : printf("\nmat2 has the maximal Trace value: %d\n",trace2);

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

int main() {
    int choice, offset1,offset2;
    printMenu();
    int q = 1;
    while (q) {

        printf("\nChoose a menu clause number:");
        scanf("%d", &choice);
        int mat, line;

        switch (choice) {
            case 1:

                printf("\nInsert offset number in range 0-9 for Mat1 generation ");
                scanf("%d", &offset1);
                printf("\nInsert offset number in range 0-9 for Mat2 generation ");
                scanf("%d", &offset2);

                createMatrices(offset1,offset2);
                break;
            case 2:
                addAndPrintMats();
                break;
            case 3:
                computeAndPrintMaximalTrace();
                break;
            case 4:
                printCombinedMaxMatrix();
                break;
            case 5:
                printf("Insert the wanted matrix by its number identifier\n1: Mat1, 2: Mat2, 3: resMat 3");
                scanf("%d", &mat);

                if (mat == 1)
                    swapDiagonal(mat1);
                if (mat == 2)
                    swapDiagonal(mat2);
                if (mat == 3)
                    swapDiagonal(resmat);
                break;
            case 6:

                printf("Insert the wanted matrix by its number identifier\n1: Mat1, 2: Mat2, 3: resMat");
                scanf("%d", &mat);

                printf("\nInsert matrix line number to sort in range 0-9 ");
                scanf("%d", &line);
                if (mat == 1)
                    sortMatrixLine(mat1, line);
                if (mat == 2)
                    sortMatrixLine(mat2, line);
                if (mat == 3)
                    sortMatrixLine(resmat, line);


                break;
            case 7:

                printf("Insert the wanted matrix by its number identifier\n1: Mat1, 2: Mat2, 3: resMat");
                scanf("%d", &mat);

                if (mat == 1){
                    printf("Mat1 =\n[\n");
                    printMatrix(mat1);
                    printf("]\n");
                }

                if (mat == 2) {
                    printf("Mat2 =\n[\n");
                    printMatrix(mat2);
                    printf("]\n");
                }
                if (mat == 3) {
                    printf("resMat1 =\n[\n");
                    printMatrix(resmat);
                    printf("]\n");
                }
                break;

            case 8:
                printMenu();
                //printf("\nChoose a menu clause number:");
                //scanf("%d", &choice);
                break;
            default:
                q = 0;

        }
    }
}

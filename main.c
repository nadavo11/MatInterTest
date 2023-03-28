#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#define ROWS 10
#define COLS 10


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

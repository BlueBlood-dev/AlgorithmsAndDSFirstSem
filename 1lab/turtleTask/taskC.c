#include <stdio.h>

int main() {
    FILE *fileIn = fopen("turtle.in","r");
    FILE *fileOut = fopen("turtle.out","w");
    int width,height;

    fscanf(fileIn,"%d%d", &height, &width);

    long long int field[height][width];

    for(int i = 0; i<height;i++){
        for(int j =0; j<width;j++){
            int variable;
            fscanf(fileIn,"%d",&variable);
            field[i][j] = variable;
        }
    }

    for(int i=height-1; i >= 0 ; i--) {
        for (int j = 0; j < width; j++) {
            if (i == height - 1 && j == 0) // first element no previous cases
                continue;
            if (i == height - 1) {// horizontal line(1 left previous case )
                field[i][j] = field[i][j - 1] + field[i][j];
                continue;
            }
            if (i != height - 1 && j == 0){//vertical line ( 1 down previous case )
                field[i][j] = field[i+1][j] + field[i][j];
                continue;
            }
            if(i!= height - 1 && j!= 0 ){    // field itself( both down and left previous cases)
                field[i][j] = field[i+1][j] > field[i][j-1]?field[i+1][j] + field[i][j]: field[i][j-1] + field[i][j];// getting max from previous cases
            }
        }
    }
//
//    for(int i = 0; i<height; i++){
//        for ( int j = 0; j < width; j++){
//            printf("%lld ", field[i][j]);
//        }
//        printf("\n");
//    }

    fprintf(fileOut,"%lld",field[0][width-1]);
    fclose(fileIn);
    fclose(fileOut);
}


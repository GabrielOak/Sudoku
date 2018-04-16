#include <stdio.h>
char matrix[9][9];
int sudoku[9][9];

void read(char matrix[9][9]){
  int i,j;
  for(i=0;i<9;i++){
    for(j=0;j<9;j++){
      scanf(" %c", &matrix[i][j]);
    }
  }
}
void transform(char matrix[9][9]){
  int i, j;
  for(i=0;i<9;i++){
    for(j=0;j<9;j++){
      if(matrix[i][j] == 'X'){
        matrix[i][j] = matrix[i][j] - 40;
      }
      sudoku[i][j] = matrix[i][j] - 48;
    }
  }
}

void print() {

  int i, j;

  for (i=0;i<9;i++) {
    for (j=0;j<9;j++) {
      printf("%d", sudoku[i][j]);
      if(j<8){
        printf(" ");
      }
      if (j>1 && j<7 && (j+1)%3 == 0){
        printf("| ");
      }
    }
    printf("\n");
    if (i>1 && i<7 && (i+1)%3 == 0){
       printf("- - - - - - - - - - -\n");
    }
  }
}

int check(int line, int column, int n) {

  int l, c, lr, cr;

  if (sudoku[line][column] == n){
    return 1;
  }
  if (sudoku[line][column] != 0){
    return 0;
  }
  for (c = 0; c < 9; c++){
    if (sudoku[line][c] == n){
      return 0;
    }
  }
  for (l = 0; l < 9; l++){
    if (sudoku[l][column] == n){
      return 0;
    }
  }
  lr = line / 3;
  cr = column / 3;
  for (l = lr * 3; l < (lr + 1) * 3; l++){
    for (c = cr * 3; c < (cr + 1) * 3; c++){
      if (sudoku[l][c] == n){
       return 0;
     }
    }
  }
  return 1;
}

void solve(int line, int column) {

  int n, t;

  if (line == 9){
    print();
  }else{
    for (n = 1; n <= 9; n++){
      if (check(line, column, n)) {
        t = sudoku[line][column];
        sudoku[line][column] = n;
        if (column == 8){
          solve(line + 1, 0);
        }else{
          solve(line, column + 1);
        }
        sudoku[line][column] = t;
      }
    }
  }

}

int main() {

  read(matrix);
  transform(matrix);
  solve(0,0);
  return 0;

}

/**
 * @file penny.c
 * Implementation of the rules of chess.
 *
 * @author Minkee Lee
 * @date Spring 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define uchar unsigned char
#define uint unsigned long

uchar inputBoard[8][8] = {
     {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
     {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
     {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
     {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
     {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
     {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
     {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
     {0x05, 0x02, 0x03, 0x09, 0x0f, 0x03, 0x02, 0x05}
};



void legalWhitePawnMoves(uchar inputBoard[8][8], int row, int col, uchar legalMoves[8][8]){
     /**
     * @todo Implement this function.
     * DON'T worry about en passant OR promotion for now
     * You are setting the legaMoves[8][8] AND legalCaptures[8][8] to be returned.
     */
     //legal move logic biatch
     if(row != 6){
       if(inputBoard[row-1][col] == 0)
          legalMoves[row-1][col] = 1; //yes yer right
     }
     else {
       if(inputBoard[row-1][col] == 0)
          legalMoves[row-1][col] = 1;
       if(inputBoard[row-2][col] == 0)
          legalMoves[row-2][col] = 1;
     }
     //legal capture
     if(col > 0 && col < 7) {
       if(inputBoard[row-1][col-1] != 0 && inputBoard[row-1][col-1] <= 6)
          legalMoves[row-1][col-1] = 1;
       if(inputBoard[row-1][col+1] != 0 && inputBoard[row-1][col+1] <= 6)
          legalMoves[row-1][col+1] = 1;
     }
     else if(col == 0) {
       if(inputBoard[row-1][col+1] != 0 && inputBoard[row-1][col+1] <= 6)
          legalMoves[row-1][col+1] = 1;
     }
     else {
       if(inputBoard[row-1][col-1] != 0 && inputBoard[row-1][col-1] <= 6)
          legalMoves[row-1][col-1] = 1;
     }
}
void  legalBlackPawnMoves(uchar inputBoard[8][8], int row, int col, uchar legalMoves[8][8]){
     /**
     * @todo Implement this function.
     * DON'T worry about en passant OR promotion for now
     * You are setting the legaMoves[8][8] AND legalCaptures[8][8] to be returned.
     */
     if(row != 1){
       if(inputBoard[row+1][col] == 0)
          legalMoves[row+1][col] = 1; //yes yer right
     }
     else {
       if(inputBoard[row+1][col] == 0)
          legalMoves[row+1][col] = 1;
       if(inputBoard[row+2][col] == 0)
          legalMoves[row+2][col] = 1;
     }
     //legal capture
     if(col > 0 && col < 7) {
       if(inputBoard[row+1][col-1] != 0 && inputBoard[row+1][col-1] > 6)
          legalMoves[row+1][col-1] = 1;
       if(inputBoard[row+1][col+1] != 0 && inputBoard[row+1][col+1] > 6)
          legalMoves[row+1][col+1] = 1;
     }
     else if(col == 0) {
       if(inputBoard[row+1][col+1] != 0 && inputBoard[row+1][col+1] > 6)
          legalMoves[row+1][col+1] = 1;
     }
     else {
       if(inputBoard[row+1][col-1] != 0 && inputBoard[row+1][col-1] > 6)
          legalMoves[row+1][col-1] = 1;
     }

}
void  legalBishopMoves(uchar inputBoard[8][8], int row, int col, uchar legalMoves[8][8]){
     /**
     * @todo Implement this function.
     * You are setting the legaMoves[8][8] AND legalCaptures[8][8] to be returned.
     */
     unsigned char bishop = inputBoard[row][col];
     int c, r;
     unsigned char s = 0x6;

     //white
     if(bishop > s) {
        //left up
       c = col-1;
       r = row-1;
       while(c >= 0 && r >= 0) {
           if(inputBoard[r][c] <= s && inputBoard[r][c] != 0) {
             legalMoves[r][c] = 1;
             break;
           }
           else if(inputBoard[r][c] == 0){
             legalMoves[r][c] = 1;
             c--;
             r--;
           }
           else {
             break;
           }

      }

       //right down
       c = col+1;
       r = row+1;
       while(c <= 7 && r <= 7) {
             if(inputBoard[r][c] <= s && inputBoard[r][c] != 0) {
               legalMoves[r][c] = 1;
               break;
             }
             else if(inputBoard[r][c] == 0){
               legalMoves[r][c] = 1;
               c++;
               r++;
             }
             else {
               break;
             }
      }

       //left down
       c = col-1;
       r = row+1;
       while(c >= 0 && r <= 7) {
         if(inputBoard[r][c] <= s && inputBoard[r][c] != 0) {
           legalMoves[r][c] = 1;
           break;
         }
         else if(inputBoard[r][c] == 0){
           legalMoves[r][c] = 1;
           c--;
           r++;
         }
         else {
           break;
         }
       }

       //right up
       c = col+1;
       r = row-1;
       while(c <= 7 && r >= 0) {
             if(inputBoard[r][c] <= s && inputBoard[r][c] != 0) {
               legalMoves[r][c] = 1;
               break;
             }
             else if(inputBoard[r][c] == 0){
               legalMoves[r][c] = 1;
               c++;
               r--;
             }
             else {
               break;
             }
      }
    }

     //black
     if(bishop <= s) {
        //left up
        c = col-1;
        r = row-1;
        while(c >= 0 && r >= 0) {
            if(inputBoard[r][c] > s && inputBoard[r][c] != 0) {
              legalMoves[r][c] = 1;
              break;
            }
            else if(inputBoard[r][c] == 0){
              legalMoves[r][c] = 1;
              c--;
              r--;
            }
            else {
              break;
            }

       }

        //right down
        c = col+1;
        r = row+1;
        while(c <= 7 && r <= 7) {
              if(inputBoard[r][c] > s && inputBoard[r][c] != 0) {
                legalMoves[r][c] = 1;
                break;
              }
              else if(inputBoard[r][c] == 0){
                legalMoves[r][c] = 1;
                c++;
                r++;
              }
              else {
                break;
              }
       }

        //left down
        c = col-1;
        r = row+1;
        while(c >= 0 && r <= 7) {
          if(inputBoard[r][c] > s && inputBoard[r][c] != 0) {
            legalMoves[r][c] = 1;
            break;
          }
          else if(inputBoard[r][c] == 0){
            legalMoves[r][c] = 1;
            c--;
            r++;
          }
          else {
            break;
          }
        }

        //right up
        c = col+1;
        r = row-1;
        while(c <= 7 && r >= 0) {
              if(inputBoard[r][c] > s && inputBoard[r][c] != 0) {
                legalMoves[r][c] = 1;
                break;
              }
              else if(inputBoard[r][c] == 0){
                legalMoves[r][c] = 1;
                c++;
                r--;
              }
              else {
                break;
              }
       }
     }

}
void legalKnightMoves(uchar inputBoard[8][8], int row, int col, uchar legalMoves[8][8]){
     /**
     * @todo Implement this function.
     * You are setting the legaMoves[8][8] AND legalCaptures[8][8] to be returned.
     */
     unsigned char Knight = inputBoard[row][col];
     unsigned char s = 0x6;

     //white
     if(Knight > s) {

       //top2 bottom2
        if(row != 0 && row != 1 && col != 0) {
          if(inputBoard[row-2][col-1] == 0 || inputBoard[row-2][col-1] <= s)
            legalMoves[row-2][col-1] = 1;
        }
        if(row != 0 && row != 1 && col != 7) {
          if(inputBoard[row-2][col+1] == 0 || inputBoard[row-2][col+1] <= s)
            legalMoves[row-2][col+1] = 1;
        }
        if(row != s && row != 7 && col != 0) {
          if(inputBoard[row+2][col-1] == 0 || inputBoard[row+2][col-1] <= s)
            legalMoves[row+2][col-1] = 1;
        }
        if(row != s && row != 7 && col != 7) {
          if(inputBoard[row+2][col+1] == 0 || inputBoard[row+2][col+1] <= s)
            legalMoves[row+2][col+1] = 1;
        }

        //left2 right2
        if(col != 0 && col != 1 && row != 0) {
          if(inputBoard[row-1][col-2] == 0 || inputBoard[row-1][col-2] <= s)
            legalMoves[row-1][col-2] = 1;
        }
        if(col != 0 && col != 1 && row != 7) {
          if(inputBoard[row+1][col-2] == 0 || inputBoard[row+1][col-2] <= s)
            legalMoves[row+1][col-2] = 1;
        }
        if(col != s && col != 7 && row != 0) {
          if(inputBoard[row-1][col+2] == 0 || inputBoard[row-1][col+2] <= s)
            legalMoves[row-1][col+2] = 1;
        }
        if(col != s && col != 7 && row != 7) {
          if(inputBoard[row+1][col+2] == 0 || inputBoard[row+1][col+2] <= s)
            legalMoves[row+1][col+2] = 1;
        }
     }

     //black
     if(Knight <= s) {

       //top2 bottom2
        if(row != 0 && row != 1 && col != 0) {
          if(inputBoard[row-2][col-1] == 0 || inputBoard[row-2][col-1] > s)
            legalMoves[row-2][col-1] = 1;
        }
        if(row != 0 && row != 1 && col != 7) {
          if(inputBoard[row-2][col+1] == 0 || inputBoard[row-2][col+1] > s)
            legalMoves[row-2][col+1] = 1;
        }
        if(row != s && row != 7 && col != 0) {
          if(inputBoard[row+2][col-1] == 0 || inputBoard[row+2][col-1] > s)
            legalMoves[row+2][col-1] = 1;
        }
        if(row != s && row != 7 && col != 7) {
          if(inputBoard[row+2][col+1] == 0 || inputBoard[row+2][col+1] > s)
            legalMoves[row+2][col+1] = 1;
        }

        //left2 right2
        if(col != 0 && col != 1 && row != 0) {
          if(inputBoard[row-1][col-2] == 0 || inputBoard[row-1][col-2] > s)
            legalMoves[row-1][col-2] = 1;
        }
        if(col != 0 && col != 1 && row != 7) {
          if(inputBoard[row+1][col-2] == 0 || inputBoard[row+1][col-2] > s)
            legalMoves[row+1][col-2] = 1;
        }
        if(col != s && col != 7 && row != 0) {
          if(inputBoard[row-1][col+2] == 0 || inputBoard[row-1][col+2] > s)
            legalMoves[row-1][col+2] = 1;
        }
        if(col != s && col != 7 && row != 7) {
          if(inputBoard[row+1][col+2] == 0 || inputBoard[row+1][col+2] > s)
            legalMoves[row+1][col+2] = 1;
        }
     }

}
void legalRookMoves(uchar inputBoard[8][8], int row, int col, uchar legalMoves[8][8]){
     /**
     * @todo Implement this function.
     * You are setting the legaMoves[8][8] AND legalCaptures[8][8] to be returned.
     */

     unsigned char rook = inputBoard[row][col];
     unsigned char s = 0x6;
     int i;

     //check leftside, rightside, down, up

     //white
     if(rook > s) {
       for(i = col-1; i >= 0; i--){
         if(inputBoard[row][i] != 0 && inputBoard[row][i] <= s) {
           legalMoves[row][i] = 1;
           break;
         }
         if(inputBoard[row][i] == 0) {
           legalMoves[row][i] = 1;
         }
         else
          break;
       }
       for(i = col+1; i <= 7; i++){
         if(inputBoard[row][i] != 0 && inputBoard[row][i] <= s) {
           legalMoves[row][i] = 1;
           break;
         }
         if(inputBoard[row][i] == 0){
           legalMoves[row][i] = 1;
         }
         else
          break;
       }
       for(i = row+1; i <= 7; i++){
         if(inputBoard[i][col] != 0 && inputBoard[i][col] <= s) {
           legalMoves[i][col] = 1;
           break;
         }
         if(inputBoard[i][col] == 0) {
           legalMoves[i][col] = 1;
         }
         else
          break;
       }
       for(i = row-1; i >= 0; i--){
         if(inputBoard[i][col] != 0 && inputBoard[i][col] <= s) {
           legalMoves[i][col] = 1;
           break;
         }
         if(inputBoard[i][col] == 0) {
           legalMoves[i][col] = 1;
         }
         else
          break;
       }
     }

     //black
     if(rook <= s) {
       for(i = col-1; i >= 0; i--){
         if(inputBoard[row][i] != 0 && inputBoard[row][i] > s) {
           legalMoves[row][i] = 1;
           break;
         }
         if(inputBoard[row][i] == 0) {
           legalMoves[row][i] = 1;
         }
         else
          break;
       }
       for(i = col+1; i <= 7; i++){
         if(inputBoard[row][i] != 0 && inputBoard[row][i] > s) {
           legalMoves[row][i] = 1;
           break;
         }
         if(inputBoard[row][i] == 0){
           legalMoves[row][i] = 1;
         }
         else
          break;
       }
       for(i = row+1; i <= 7; i++){
         if(inputBoard[i][col] != 0 && inputBoard[i][col] > s) {
           legalMoves[i][col] = 1;
           break;
         }
         if(inputBoard[i][col] == 0) {
           legalMoves[i][col] = 1;
         }
         else
          break;
       }
       for(i = row-1; i >= 0; i--){
         if(inputBoard[i][col] != 0 && inputBoard[i][col] > s) {
           legalMoves[i][col] = 1;
           break;
         }
         if(inputBoard[i][col] == 0) {
           legalMoves[i][col] = 1;
         }
         else
          break;
       }
     }


}
void legalQueenMoves(uchar inputBoard[8][8], int row, int col, uchar legalMoves[8][8]){
     /**
     * @todo Implement this function.
     * You are setting the legaMoves[8][8] AND legalCaptures[8][8] to be returned.
     */
     unsigned char queen = inputBoard[row][col];
     unsigned char s = 0x6;
     int c, r, i;

     //white
     if(queen > s) {
       c = col-1;
       r = row-1;
       while(c >= 0 && r >= 0) {
           if(inputBoard[r][c] <= s && inputBoard[r][c] != 0) {
             legalMoves[r][c] = 1;
             break;
           }
           else if(inputBoard[r][c] == 0){
             legalMoves[r][c] = 1;
             c--;
             r--;
           }
           else {
             break;
           }

      }

       //right down
       c = col+1;
       r = row+1;
       while(c <= 7 && r <= 7) {
             if(inputBoard[r][c] <= s && inputBoard[r][c] != 0) {
               legalMoves[r][c] = 1;
               break;
             }
             else if(inputBoard[r][c] == 0){
               legalMoves[r][c] = 1;
               c++;
               r++;
             }
             else {
               break;
             }
      }

       //left down
       c = col-1;
       r = row+1;
       while(c >= 0 && r <= 7) {
         if(inputBoard[r][c] <= s && inputBoard[r][c] != 0) {
           legalMoves[r][c] = 1;
           break;
         }
         else if(inputBoard[r][c] == 0){
           legalMoves[r][c] = 1;
           c--;
           r++;
         }
         else {
           break;
         }
       }

       //right up
       c = col+1;
       r = row-1;
       while(c <= 7 && r >= 0) {
             if(inputBoard[r][c] <= s && inputBoard[r][c] != 0) {
               legalMoves[r][c] = 1;
               break;
             }
             else if(inputBoard[r][c] == 0){
               legalMoves[r][c] = 1;
               c++;
               r--;
             }
             else {
               break;
             }
      }
        //up down left right
        for(i = col-1; i >= 0; i--){
          if(inputBoard[row][i] != 0 && inputBoard[row][i] <= s) {
            legalMoves[row][i] = 1;
            break;
          }
          if(inputBoard[row][i] == 0) {
            legalMoves[row][i] = 1;
          }
          else
           break;
        }
        for(i = col+1; i <= 7; i++){
          if(inputBoard[row][i] != 0 && inputBoard[row][i] <= s) {
            legalMoves[row][i] = 1;
            break;
          }
          if(inputBoard[row][i] == 0){
            legalMoves[row][i] = 1;
          }
          else
           break;
        }
        for(i = row+1; i <= 7; i++){
          if(inputBoard[i][col] != 0 && inputBoard[i][col] <= s) {
            legalMoves[i][col] = 1;
            break;
          }
          if(inputBoard[i][col] == 0) {
            legalMoves[i][col] = 1;
          }
          else
           break;
        }
        for(i = row-1; i >= 0; i--){
          if(inputBoard[i][col] != 0 && inputBoard[i][col] <= s) {
            legalMoves[i][col] = 1;
            break;
          }
          if(inputBoard[i][col] == 0) {
            legalMoves[i][col] = 1;
          }
          else
           break;
        }
     }

     //black
     if(queen <= s) {
       c = col-1;
       r = row-1;
       while(c >= 0 && r >= 0) {
           if(inputBoard[r][c] > s && inputBoard[r][c] != 0) {
             legalMoves[r][c] = 1;
             break;
           }
           else if(inputBoard[r][c] == 0){
             legalMoves[r][c] = 1;
             c--;
             r--;
           }
           else {
             break;
           }

      }

       //right down
       c = col+1;
       r = row+1;
       while(c <= 7 && r <= 7) {
             if(inputBoard[r][c] > s && inputBoard[r][c] != 0) {
               legalMoves[r][c] = 1;
               break;
             }
             else if(inputBoard[r][c] == 0){
               legalMoves[r][c] = 1;
               c++;
               r++;
             }
             else {
               break;
             }
      }

       //left down
       c = col-1;
       r = row+1;
       while(c >= 0 && r <= 7) {
         if(inputBoard[r][c] > s && inputBoard[r][c] != 0) {
           legalMoves[r][c] = 1;
           break;
         }
         else if(inputBoard[r][c] == 0){
           legalMoves[r][c] = 1;
           c--;
           r++;
         }
         else {
           break;
         }
       }

       //right up
       c = col+1;
       r = row-1;
       while(c <= 7 && r >= 0) {
             if(inputBoard[r][c] > s && inputBoard[r][c] != 0) {
               legalMoves[r][c] = 1;
               break;
             }
             else if(inputBoard[r][c] == 0){
               legalMoves[r][c] = 1;
               c++;
               r--;
             }
             else {
               break;
             }
      }

       //up down left right
       for(i = col-1; i >= 0; i--){
         if(inputBoard[row][i] != 0 && inputBoard[row][i] > s) {
           legalMoves[row][i] = 1;
           break;
         }
         if(inputBoard[row][i] == 0) {
           legalMoves[row][i] = 1;
         }
         else
          break;
       }
       for(i = col+1; i <= 7; i++){
         if(inputBoard[row][i] != 0 && inputBoard[row][i] > s) {
           legalMoves[row][i] = 1;
           break;
         }
         if(inputBoard[row][i] == 0){
           legalMoves[row][i] = 1;
         }
         else
          break;
       }
       for(i = row+1; i <= 7; i++){
         if(inputBoard[i][col] != 0 && inputBoard[i][col] > s) {
           legalMoves[i][col] = 1;
           break;
         }
         if(inputBoard[i][col] == 0) {
           legalMoves[i][col] = 1;
         }
         else
          break;
       }
       for(i = row-1; i >= 0; i--){
         if(inputBoard[i][col] != 0 && inputBoard[i][col] > s) {
           legalMoves[i][col] = 1;
           break;
         }
         if(inputBoard[i][col] == 0) {
           legalMoves[i][col] = 1;
         }
         else
          break;
       }
     }

}
void legalWhiteKingMoves(uchar inputBoard[8][8], int row, int col, uchar legalMoves[8][8]){
     /**
     * @todo Implement this function.
     * DON'T worry about castling for now
     * You are setting the legaMoves[8][8] AND legalCaptures[8][8] to be returned.
     */
     //int king = inputBoard[row][col];
     //white
     //if(king > s) {
     unsigned char s = 0x6;
        if(row != 0 && col != 0) {
          if(inputBoard[row-1][col-1] == 0 || inputBoard[row-1][col-1] <= s)
            legalMoves[row-1][col-1] = 1;
        }
        if(row != 0) {
          if(inputBoard[row-1][col] == 0 || inputBoard[row-1][col] <= s)
            legalMoves[row-1][col] = 1;
        }
        if(row != 0 && col != 7) {
          if(inputBoard[row-1][col+1] == 0 || inputBoard[row-1][col+1] <= s)
            legalMoves[row-1][col+1] = 1;
        }
        if(col != 0) {
          if(inputBoard[row][col-1] == 0 || inputBoard[row][col-1] <= s)
            legalMoves[row][col-1] = 1;
        }
        if(col != 7) {
          if(inputBoard[row][col+1] == 0 || inputBoard[row][col+1] <= s)
            legalMoves[row][col+1] = 1;
        }
        if(row != 7 && col != 0) {
          if(inputBoard[row+1][col-1] == 0 || inputBoard[row+1][col-1] <= s)
            legalMoves[row+1][col-1] = 1;
        }
        if(row != 7) {
          if(inputBoard[row+1][col] == 0 || inputBoard[row+1][col] <= s)
            legalMoves[row+1][col] = 1;
        }
        if(row != 7 && col != 7) {
          if(inputBoard[row+1][col+1] == 0 || inputBoard[row+1][col+1] <= s)
            legalMoves[row+1][col+1] = 1;
       }
     //}

     //castle

     if(row == 7 && col == 4) {
       //0-0
       if(inputBoard[7][5] == 0 && inputBoard[7][s] == 0 && inputBoard[7][7] == 9){
         legalMoves[7][s] = 2;
       }
       //0-0-0
       if(inputBoard[7][3] == 0 && inputBoard[7][2] == 0 && inputBoard[7][1] == 0 && inputBoard[7][0] == 9){
         legalMoves[7][2] = 3;
       }
     }

}

void legalBlackKingMoves(uchar inputBoard[8][8], int row, int col, uchar legalMoves[8][8]){
     /**
     * @todo Implement this function.
     * DON'T worry about castling for now
     * You are setting the legaMoves[8][8] AND legalCaptures[8][8] to be returned.
     */
     //int king = inputBoard[row][col];

     //black
     //
     unsigned char s = 0x6;
       if(row != 0 && col != 0) {
          if(inputBoard[row-1][col-1] == 0 || inputBoard[row-1][col-1] > s)
            legalMoves[row-1][col-1] = 1;
        }
        if(row != 0) {
          if(inputBoard[row-1][col] == 0 || inputBoard[row-1][col] > s)
            legalMoves[row-1][col] = 1;
        }
        if(row != 0 && col != 7) {
          if(inputBoard[row-1][col+1] == 0 || inputBoard[row-1][col+1] > s)
            legalMoves[row-1][col+1] = 1;
        }
        if(col != 0) {
          if(inputBoard[row][col-1] == 0 || inputBoard[row][col-1] > s)
            legalMoves[row][col-1] = 1;
        }
        if(col != 7) {
          if(inputBoard[row][col+1] == 0 || inputBoard[row][col+1] > s)
            legalMoves[row][col+1] = 1;
        }
        if(row != 7 && col != 0) {
          if(inputBoard[row+1][col-1] == 0 || inputBoard[row+1][col-1] > s)
            legalMoves[row+1][col-1] = 1;
        }
        if(row != 7) {
          if(inputBoard[row+1][col] == 0 || inputBoard[row+1][col] > s)
            legalMoves[row+1][col] = 1;
        }
        if(row != 7 && col != 7) {
          if(inputBoard[row+1][col+1] == 0 || inputBoard[row+1][col+1] > s)
            legalMoves[row+1][col+1] = 1;
       }
     //}

     //0-0 and 0-0-0

     if(row == 0 && col == 4) {
       //0-0
       if(inputBoard[0][5] == 0 && inputBoard[0][s] == 0 && inputBoard[0][7] == 3){
         legalMoves[0][6] = 2;
       }
       //0-0-0
       if(inputBoard[0][3] == 0 && inputBoard[0][2] == 0 && inputBoard[0][1] == 0 && inputBoard[0][0] == 3){
         legalMoves[0][2] = 3;
       }
     }

}

int main()
{
  return 0;
}

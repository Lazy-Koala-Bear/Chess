#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define uchar unsigned char
#define uint unsigned long
uchar pointValues[7] = {
     0x00, 0x01, 0x03, 0x03, 0x05, 0x09, 0x80
}
uchar whitePieces[8][8] = {
     {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
     {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
     {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
     {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
     {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
     {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
     {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
     {0x05, 0x02, 0x03, 0x09, 0x0f, 0x03, 0x02, 0x05}
}
uchar blackPieces[8][8] = {
     {0x05, 0x02, 0x03, 0x09, 0x0f, 0x03, 0x02, 0x05},
     {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
     {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
     {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
     {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
     {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
     {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
     {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
};

struct whitePawn{
     int alive; //if 1, alive. if 0, dead.
     int row;
     int column;
     int color = 1; //if 1, white. if 0, black
     int point;
};
struct whiteBishop{
     int alive; //if 1, alive. if 0, dead.
     int row;
     int column;
     int color = 1; //if 1, white. if 0, black
     int point;
};
struct whiteKnight{
     int alive; //if 1, alive. if 0, dead.
     int row;
     int column;
     int color = 1; //if 1, white. if 0, black
     int point;
};
struct whiteRook{
     int alive; //if 1, alive. if 0, dead.
     int row;
     int column;
     int color = 1; //if 1, white. if 0, black
     int point;
};
struct whiteQueen{
     int alive; //if 1, alive. if 0, dead.
     int row;
     int column;
     int color = 1; //if 1, white. if 0, black
     int point;
};
struct whiteKing{
     int alive;
     //int moved; //worry about this later
     int row;
     int column;
     int color = 1;
     int point;
};
//BLACK pieces
struct blackPawn{
     int alive; //if 1, alive. if 0, dead.
     int row;
     int column;
     int color = 0; //if 1, white. if 0, black
     int point;
};
struct blackBishop{
     int alive; //if 1, alive. if 0, dead.
     int row;
     int column;
     int color = 0; //if 1, white. if 0, black
     int point;
};
struct blackKnight{
     int alive; //if 1, alive. if 0, dead.
     int row;
     int column;
     int color = 0; //if 1, white. if 0, black
     int point;
};
struct blackRook{
     int alive; //if 1, alive. if 0, dead.
     int row;
     int column;
     int color = 0; //if 1, white. if 0, black
     int point;
};
struct blackQueen{
     int alive; //if 1, alive. if 0, dead.
     int row;
     int column;
     int color = 0; //if 1, white. if 0, black
     int point;
};
struct blackKing{
     int alive;
     //int moved; //worry about this later
     int row;
     int column;
     int color = 0;
     int point;
};
void boardInitialize(){
     *to_hw_sig = 1;
     while(*to_sw_sig != 1);
     *to_hw_sig = 0;
}
int main(){
     // Start with pressing reset
	*to_hw_sig = 0;
	*to_hw_port = 0;
	printf("Press reset!\n");
	while (*to_sw_sig != 3);

     struct whitePawn whiteapawn, whitebpawn, whitecpawn,
            whitedpawn, whiteepawn, whitefpawn, whitegpawn, whitehpawn;
     struct whiteBishop whiteLSB, whiteDSB;
     struct whiteKnight whiteKnightOne, whiteKnightTwo;
     struct whiteRook whiteRookOne, whiteRookTwo;
     struct whiteQueen whitequeen;
     struct whiteKing whiteking;
     struct blackPawn blackapawn, blackbpawn, blackcpawn,
            blackdpawn, blackepawn, blackfpawn, blackgpawn, blackhpawn;
     struct blackBishop blackLSB, blackDSB;
     struct blackKnight blackKnightOne, blackKnightTwo;
     struct blackRook blackRookOne, whiteRookTwo;
     struct blackQueen blackqueen;
     struct blackKing blackking;
     //declare white pawns
     whiteapawn.alive = 1; whiteapawn.row = 6; whiteapawn.column = 0;
     whitebpawn.alive = 1; whitebpawn.row = 6; whitebpawn.column = 1;
     whitecpawn.alive = 1; whitecpawn.row = 6; whitecpawn.column = 2;
     whitedpawn.alive = 1; whitedpawn.row = 6; whitedpawn.column = 3;
     whiteepawn.alive = 1; whiteepawn.row = 6; whiteepawn.column = 4;
     whitefpawn.alive = 1; whitefpawn.row = 6; whitefpawn.column = 5;
     whitegpawn.alive = 1; whitegpawn.row = 6; whitegpawn.column = 6;
     whitehpawn.alive = 1; whitehpawn.row = 6; whitehpawn.column = 7;

     //declare white bishops + knights + rooks + kings and queens
     whiteLSB.alive = 1; whiteLSB.row = 7; whiteLSB.column = 5;
     whiteDSB.alive = 1; whiteDSB.row = 7; whiteDSB.column = 2;
     whiteKnightOne.alive = 1; whiteKnightOne.row = 7; whiteKnightOne.column = 1;
     whiteKnightTwo.alive = 1; whiteKnightTwo.row = 7; whiteKnightTwo.column = 6;
     whiteRookOne.alive = 1; whiteRookOne.row = 7; whiteRookTwo.column = 0;
     whiteRookTwo.alive = 1; whiteRookTwo.row = 7; whiteRookTwo.column = 7;
     whitequeen.alive = 1; whitequeen.row = 7; whitequeen.column = 3;
     whiteking.alive = 1; whiteking.row = 7; whiteking.column = 4;

     //declare black pawns
     blackapawn.alive = 1; blackapawn.row = 1; blackapawn.column = 0;
     blackbpawn.alive = 1; blackbpawn.row = 1; blackbpawn.column = 1;
     blackcpawn.alive = 1; blackcpawn.row = 1; blackcpawn.column = 2;
     blackdpawn.alive = 1; blackdpawn.row = 1; blackdpawn.column = 3;
     blackepawn.alive = 1; blackepawn.row = 1; blackepawn.column = 4;
     blackfpawn.alive = 1; blackfpawn.row = 1; blackfpawn.column = 5;
     blackgpawn.alive = 1; blackgpawn.row = 1; blackgpawn.column = 6;
     blackhpawn.alive = 1; blackhpawn.row = 1; blackhpawn.column = 7;

     //declare black bishops + knights + rooks + kings and queens
     blackLSB.alive = 1; blackLSB.row = 0; blackLSB.column = 2;
     blackDSB.alive = 1; blackDSB.row = 0; blackDSB.column = 5;
     blackKnightOne.alive = 1; blackKnightOne.row = 0; blackKnightOne.column = 1;
     blackKnightTwo.alive = 1; blackKnightTwo.row = 0; blackKnightTwo.column = 6;
     blackRookOne.alive = 1; blackRookOne.row = 0; blackRookOne.column = 0;
     blackRookTwo.alive = 1; blackRookTwo.row = 0; blackRookTwo.column = 7;
     blackqueen.alive = 1; blackqueen.row = 0; blackqueen.column = 3;
     blackking.alive = 1; blackking.row = 0; blackking.column = 4;

     //Checkpoint 1: Pass the reset signal for the board
     boardInitialize();
     while (1){

          //Checkpoint 2:

     }
     return 0;
}

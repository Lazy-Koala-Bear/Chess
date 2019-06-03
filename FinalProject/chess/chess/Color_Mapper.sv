//-------------------------------------------------------------------------
//    Color_Mapper.sv                                                    --
//    Stephen Kempf                                                      --
//    3-1-06                                                             --
//                                                                       --
//    Modified by David Kesler  07-16-2008                               --
//    Translated by Joe Meng    07-07-2013                               --
//    Modified by Po-Han Huang  03-03-2017                               --
//                                                                       --
//    Spring 2017 Distribution                                           --
//                                                                       --
//    For use with ECE 385 Lab 7                                         --
//    University of Illinois ECE Department                              --
//-------------------------------------------------------------------------


module  color_mapper (
                       input [9:0] DrawX, DrawY,       // Coordinates of current drawing pixel
                       //input Clk,
							  input [11:0] pieceSelect,
							  //input [3:0] Row, Column,
							  output logic [7:0] VGA_R, VGA_G, VGA_B // VGA RGB output
                     );
		/*					
	 logic [10:0] minX, minY;
	 logic [6:0] index;
	 assign index = Row * 8 + Column;
	 ChessBoard board_inst(.clk(Clk),
                     .index(index) ,
                     .minX(minX),
						   .minY(minY));
		*/
	 
	 /*
	 generate
    genvar i;
		for (i=0; i < 1024; i++)
		begin : gen1
			ball_mapper ball_inst (Clk, BallSize[i], BallColor[i], DrawX, DrawY, BallX[i], BallY[i], ball_R[i], ball_G[i], ball_B[i]);
		end
	 endgenerate
	 */
	 logic [1:0] background, color, whitePawn;
	 logic [18:0] read_address;
	 assign read_address = (DrawY %32) * 32 + (DrawX %32);
	 frameROM white_pawn_inst(read_address(read_address), .Clk(Clk), .data_Out(whitePawn));
        
    // Compute whether the pixel corresponds to ball or background
    always_comb
    begin : Chess Board + Background 
        if ((DrawX[5] == 1'b1 | DrawY[5] == 1'b1) & (DrawX[5] != DrawY[5])) 
            background = 2'b01;
		  else if((DrawX[8]|DrawX[9])&(DrawY[8]|DrawY[9]))
				background = 2'b10;
        else 
            background = 2'b00;
    end
	 
	 always_comb
	 begin : Draw the pieces
			case(pieceSelect)
				12'b000000000000 : color = 2'd0;
				12'b100000000000 : color = whitePawn;
				default : color = 2'd0
			endcase
	 end 
    
    // Assign color based on background, then by piece
    always_comb
    begin : RGB_Display
		  if(pieceSelect[11]|pieceSelect[10]|pieceSelect[9]|pieceSelect[8]|pieceSelect[7]|pieceSelect[6]|pieceSelect[5]|
		     pieceSelect[4] |pieceSelect[3] |pieceSelect[2]|pieceSelect[1]|pieceSelect[0])
		  begin
				case(color)
					
				endcase
		  end
        else if ((background == 2'b01)) 
        begin
            // Black Square
            VGA_R = 8'h00;
            VGA_G = 8'h00;
            VGA_B = 8'h00;
        end
		  else if((background == 2'b10))
		  begin
				VGA_R = 8'he1;
				VGA_G = 8'hb1;
				VGA_B = 8'hb1;
		  end
        else 
        begin
            // White Background
            VGA_R = 8'hff; 
            VGA_G = 8'hff;
            VGA_B = 8'hff;
        end
    end 
    
endmodule

module ChessBoard  ( input              clk,
                     input logic       [6:0] index ,
                     output logic [10:0] minX,
						   output logic [10:0] minY);

 // This module will be synthesized into a ROM
    always_ff @ (posedge clk)
    case (in)
    8'h00: begin minX <= 11'd0; minY <= 11'd0; end    8'h01: begin minX <= 11'd32; minY <= 11'd0; end   
	 8'h02: begin minX <= 11'd64; minY <= 11'd0; end    8'h03: begin minX <= 11'd96; minY <= 11'd0; end
    8'h04: begin minX <= 11'd128; minY <= 11'd0; end    8'h05: begin minX <= 11'd160; minY <= 11'd0; end    
	 8'h06: begin minX <= 11'd192; minY <= 11'd0; end    8'h07: begin minX <= 11'd224; minY <= 11'd0; end
    8'h08: begin minX <= 11'd0; minY <= 11'd32; end    8'h09: begin minX <= 11'd32; minY <= 11'd32; end    
	 8'h0a: begin minX <= 11'd64; minY <= 11'd32; end    8'h0b: begin minX <= 11'd96; minY <= 11'd32; end
    8'h0c: begin minX <= 11'd128; minY <= 11'd32; end    8'h0d: begin minX <= 11'd160; minY <= 11'd32; end 
	 8'h0e: begin minX <= 11'd192; minY <= 11'd32; end    8'h0f: begin minX <= 11'd224; minY <= 11'd32; end
    8'h10: begin minX <= 11'd0; minY <= 11'd64; end    8'h11: begin minX <= 11'd32; minY <= 11'd64; end  
	 8'h12: begin minX <= 11'd64; minY <= 11'd64; end    8'h13: begin minX <= 11'd96; minY <= 11'd64; end
    8'h14: begin minX <= 11'd128; minY <= 11'd64; end    8'h15: begin minX <= 11'd160; minY <= 11'd64; end    
	 8'h16: begin minX <= 11'd192; minY <= 11'd64; end    8'h17: begin minX <= 11'd224; minY <= 11'd64; end
    8'h18: begin minX <= 11'd0; minY <= 11'd96; end    8'h19: begin minX <= 11'd32; minY <= 11'd96; end   
	 8'h1a: begin minX <= 11'd64; minY <= 11'd96; end    8'h1b: begin minX <= 11'd96; minY <= 11'd96; end
    8'h1c: begin minX <= 11'd128; minY <= 11'd96; end    8'h1d: begin minX <= 11'd160; minY <= 11'd96; end  
	 8'h1e: begin minX <= 11'd192; minY <= 11'd96; end    8'h1f: begin minX <= 11'd224; minY <= 11'd96; end
    8'h20: begin minX <= 11'd0; minY <= 11'd128; end    8'h21: begin minX <= 11'd32; minY <= 11'd128; end    
	 8'h22: begin minX <= 11'd64; minY <= 11'd128; end    8'h23: begin minX <= 11'd96; minY <= 11'd128; end
    8'h24: begin minX <= 11'd128; minY <= 11'd128; end    8'h25: begin minX <= 11'd160; minY <= 11'd128; end   
	 8'h26: begin minX <= 11'd192; minY <= 11'd128; end    8'h27: begin minX <= 11'd224; minY <= 11'd128; end
    8'h28: begin minX <= 11'd0; minY <= 11'd160; end    8'h29: begin minX <= 11'd32; minY <= 11'd160; end    
	 8'h2a: begin minX <= 11'd64; minY <= 11'd160; end    8'h2b: begin minX <= 11'd96; minY <= 11'd160; end
    8'h2c: begin minX <= 11'd128; minY <= 11'd160; end    8'h2d: begin minX <= 11'd160; minY <= 11'd160; end   
	 8'h2e: begin minX <= 11'd192; minY <= 11'd160; end    8'h2f: begin minX <= 11'd224; minY <= 11'd160; end
    8'h30: begin minX <= 11'd0; minY <= 11'd192; end    8'h31: begin minX <= 11'd32; minY <= 11'd192; end   
	 8'h32: begin minX <= 11'd64; minY <= 11'd192; end    8'h33: begin minX <= 11'd96; minY <= 11'd192; end
    8'h34: begin minX <= 11'd128; minY <= 11'd192; end    8'h35: begin minX <= 11'd160; minY <= 11'd192; end   
	 8'h36: begin minX <= 11'd192; minY <= 11'd192; end    8'h37: begin minX <= 11'd224; minY <= 11'd192; end
    8'h38: begin minX <= 11'd0; minY <= 11'd224; end    8'h39: begin minX <= 11'd32; minY <= 11'd224; end   
	 8'h3a: begin minX <= 11'd64; minY <= 11'd224; end    8'h3b: begin minX <= 11'd96; minY <= 11'd224; end
    8'h3c: begin minX <= 11'd128; minY <= 11'd224; end    8'h3d: begin minX <= 11'd160; minY <= 11'd224; end   
	 8'h3e: begin minX <= 11'd192; minY <= 11'd224; end    8'h3f: begin minX <= 11'd224; minY <= 11'd224; end
    endcase
endmodule
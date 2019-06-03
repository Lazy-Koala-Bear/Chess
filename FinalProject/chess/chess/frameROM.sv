/*
 * ECE385-HelperTools/PNG-To-Txt
 * Author: Rishi Thakkar
 *
 */

module  frameROM
(
		input [18:0] read_address,
		input Clk,

		output logic [1:0] data_Out
);

// mem has width of 2 bits and a total of 1024 addresses
logic [1:0] mem [0:3135];

initial
begin
	 $readmemh("wP2.txt", mem);
end


always_ff @ (posedge Clk) begin
	data_Out<= mem[read_address];
end
endmodule 
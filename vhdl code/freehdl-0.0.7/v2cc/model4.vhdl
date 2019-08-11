-- testbench to test the adder 
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity model4 is 
end model4;

-- This is a comment
architecture struct of model4 is
	signal data1, result : unsigned(0 to 7) := (others => '0');
	signal data2 : unsigned(0 to 7) := (7 => '1', others => '0');
	signal clk : bit;
begin

 clk <= not clk after 10 ns;

 process
 begin
	result <= result + data2;
	data1 <= (data1(0 to 6) & data1(0)) - result;	
	wait on clk until clk = '1';
 end process;

end struct;


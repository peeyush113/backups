-----------------------------------------------------------
-- Example VHDL file
-----------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity model is 
  generic (gen : integer := 10);
  port (port_sig1:bit_vector(15 downto 0));
end model;

-- This is a comment
--use work.all;
architecture struct of model is
	--type myarray is array (positive range <>) of integer;

	type color is ('z', black, wihte, red, green, yellow, blue); 

	signal col : color := 'z';
	subtype kol is bit_vector(0 to 7) ;
	type lop is array (5 downto 2) of integer;
	type lop1 is array (0 to 1) of kol;
	type lop11 is array (0 to 2) of lop1;
        signal int1: integer := 4;
	signal a : std_logic_vector(1 to 16):= "0001110110011111";
	signal b : std_logic_vector(1 to 16):= (1|2|4|8|12|15 => '1', others =>'0');
	signal c : std_logic_vector(1 to 16):= (others => '0');
	signal a1 : bit_vector(15 downto 0) := "1011110110011111";
	signal b1 : bit_vector(15 downto 0) := (0|2|4|6|8|10 => '1', others =>'0');
	signal c1 : bit_vector(15 downto 0) := (others => '1');
	signal d1 : bit_vector(0 to 7) := "10011101";
	signal int : integer := 4;
	signal clk : bit;
	constant const: integer:= 5;
	signal col1: color := blue;
	constant ccc : integer := gen;

begin 

p: process (int)
	procedure proc(a : in integer) is
	begin
		report "message!";
	end proc;
 begin
	
   int <=  int + 1 after 10 ns;
   
 end process;
end struct;




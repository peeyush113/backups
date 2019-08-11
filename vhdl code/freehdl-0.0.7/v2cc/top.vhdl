-----------------------------------------------------------
-- Example VHDL file
-----------------------------------------------------------

-----------------------------------------------------------
-- A simple generic adder testbench
--
-- INSTRUCTIONS:
-- First, compile module adder. Then execute
-- "gvhdl top.vhdl adder.o ../ieee/std_logic_1164.o
-- This will create a simulator "top" for module top.
-----------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity top is 
 port(x, y, z: in bit_vector(15 downto 0) := (others => '0');
	v : out std_logic_vector(7 downto 0) := (others =>'1'));
	
end top;

use work.adder;
architecture arch of top is
	signal a : std_logic_vector(1 to 16) := "0001110110011111";
	signal b : std_logic_vector(1 to 16) := (1|2|4|8|12|15 => '1', others =>'0');
	signal c : std_logic_vector(1 to 16) := (others => '0');
	signal al, ah : std_logic_vector(0 to 7);
	signal clk : bit;
begin

 clk <= not clk after 10 ns;

 addcomp1: entity adder 
	port map (a => a,  b => b, q => c);

 addcomp2: entity adder 
	port map (a => al,  b => ah, q => v);

 -- generate input values
 p: process (clk)
 begin
	if clk'event and clk = '1' then
		a <= a(2 to 16) & a(1);
		b <= b(2 to 16) & b(1);
		ah <= c(1 to 8) after 3 ns;
		al <= c(9 to 16) after 3 ns;
	end if;
 end process;
end arch;


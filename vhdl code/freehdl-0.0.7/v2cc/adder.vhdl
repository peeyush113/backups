-----------------------------------------------------------
-- Example VHDL file
-----------------------------------------------------------

-----------------------------------------------------------
-- A simple generic adder
--
-- INSTRUCTIONS:
-- Compile this module with
-- "gvhdl -c adder.vhdl"
-----------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity adder is 
 	-- Currently, no generics are supported
	port (a, b : in std_logic_vector;
	      q : out std_logic_vector);
end adder;

architecture arch of adder is

begin
 p: process (a,b)
	variable ov : std_ulogic;
	variable av, bv, qv : std_logic_vector(0 to a'length - 1);
 begin
	av := a;
	bv := b;
	ov := '0';
	for i in av'high downto 0 loop
		qv(i) := av(i) xor bv(i) xor ov;
		if (av(i) = '1' and bv(i) = '1') or
		   (ov = '1' and bv(i) = '1') or
		   (av(i) = '1' and ov = '1') then
		 	ov := '1';
		else
			ov := '0';
		end if;
	end loop;
	q <= qv;
 end process;
end arch;


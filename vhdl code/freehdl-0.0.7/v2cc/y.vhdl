-----------------------------------------------------------
-- Example VHDL file
-----------------------------------------------------------

-----------------------------------------------------------
-- Example VHDL file
-----------------------------------------------------------

-- A simple 8 bit adder


entity adder2 is 
 	-- Currently, no generics are supported
	generic (gen : integer := 10);
	port (a, b : in bit_vector(1 to 8);
	      q : out bit_vector(1 to 8));
end adder2;

architecture arch of adder2 is

begin
 p: process (a,b)
	variable ov : bit;
 begin
	ov := '0';
	for i in 8 downto 1 loop
		q(i) <= a(i) xor b(i) xor ov;
		if (a(i) = '1' and b(i) = '1') or
		   (ov = '1' and b(i) = '1') or
		   (a(i) = '1' and ov = '1') then
		 	ov := '1';
		else
			ov := '0';
		end if;
	end loop;
 end process;
end arch;

use WORK.adder2;
-- testbench to test the adder 
entity model is 
end model;

-- This is a comment
architecture struct of model is
	signal asig, bsig, qsig, qsig2 : bit_vector(1 to 8) := (3 | 4 | 6 => '1', others => '0');
	signal clk : bit := '0';
	--signal x : integer :=8;
	component adder2  
 	-- Currently, no generics are supported
	port (a, b : in bit_vector(1 to 8);
	      q : out bit_vector(1 to 8));
	end component;

begin

 -- Instantiate the adder circuit
 addcomp: adder2
	port map(a => asig, b => bsig, q => qsig);
 
 addselect: adder2 port map(a => asig, b => bsig, q => qsig2);

 clk <= not clk after 10 ns;

 process
 begin	
	-- Generate some test vectors for the
	-- adder
	asig <= (not asig(8)) & asig(1 to 7);
	bsig <= asig(2 to 8) & (not bsig(1));
	wait until clk = '1';
 end process;

end struct;


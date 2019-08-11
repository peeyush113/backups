package mypack is
	type bvec2d is array (0 to 1, 0 to 1) of bit;
end package;

use work.mypack.all;
entity adder is 
 	-- Currently, no generics are supported
	generic (gen1, gen2 : bit_vector (1 to 3));
	port (x : in bit_vector(1 to 4);
	      y : in bvec2d);
end adder;

architecture arch of adder is
	signal a, b, q : bit_vector(1 to 8);
begin
 p: process (a,b)
	variable ov : bit;
 begin
	ov := '0';
 end process;
end arch;

use work.mypack.all;
entity ccc is
	port (a : out bit_vector(0 to 3));
end ccc;

architecture arch of ccc is
begin
	a <= "0001";
end arch;


-- This design is used to test the error detection
-- routines of the compiler. Note that it contains
-- a lot if illegal code!
use work.mypack.all;
entity tveccomp is 
 	-- Currently, no generics are supported
	generic (gen : integer);
	port (bvec : inout bit_vector(0 to 7));
end tveccomp;

use work.ccc;
use work.adder;
architecture arch of tveccomp is
	type colors is (red, green, yellow, black, wheat, white);
	subtype colors2 is colors range green to yellow;
	subtype myint is positive range gen to 200;
	subtype bvec_type is bit_vector(1 to 10);
	subtype bvec_type2 is bvec_type(0 to 11);
	subtype bvec_type3 is bit_vector(1 to 3);
	signal clk : bit;
	signal int1 : positive;
	signal int2 : myint := 300;
	signal col1 : colors;
	signal col2 : colors2;
	signal sig1 : bit_vector(0 to 3);
	signal sig2 : bit_vector(0 to 3);

	signal ysig :  bvec2d;
	signal xsig : bit_vector(2 downto 0);
begin
	process (clk)
		variable t : time;
		constant creal : real := -1.0;
		variable cpos : positive;
		variable bbb : bvec_type3;
		
		function func return positive is 
			subtype myint2 is myint range 1 to 200;
			variable var : myint2;
		begin
			var := 0;
			return -1;
		end func;	
	begin
		case int1 is
		when 2 => clk <= not clk;	
		when 10 => clk <= not clk;	
		when 12 => clk <= not clk;	
		when 100 => clk <= not clk;
		end case;

		case int2 is
		when 100 to 140 => clk <= not clk;
		when 141 to 180 => clk <= not clk;
		end case;
	
		case col1 is
		when red => clk <= not clk;
		when red to black => clk <= not clk;
		end case;

		case col1 is
		when others => clk <= not clk;
		when red => clk <= not clk;
		end case;
		
		case col2 is
		when green => clk <= not clk;
		end case;

		t := time(int1);
		cpos := positive(creal);

		case bbb is
		when "001" => clk <= not clk;
		when "1001" => clk <= not clk;
		when "011" | "001" => clk <= not clk;
		when "011" to "001" => clk <= not clk;
		when others => clk <= not clk;
		end case;
	
		case bbb is
		when "001" => clk <= not clk;
		when "011" | "010" => clk <= not clk;
		end case;	

		bbb := "1111";
	end process;

qq2: entity ccc port map (
	a(0 to 2) => sig2(1 to 2),	
	a(0 to 1) => sig2,
	a(2 to 3) => sig2(1 to 2)
	);

qq1: entity ccc port map (
	a(0) => sig1(0), a(1) => sig1(1), a(2) => sig1(2), a(4) => sig1(3)
	);

qq3: entity adder
	generic map (
		gen1 => "11111",
		gen2(1) => '0',
		gen2(2) => '0',
		gen2(3) => '0',
		gen2(1) => '0'
	)
	port map(
		x(4) => xsig(0),
		x(1) => xsig(0),
		--x(2) => xsig(1),
		x(4) => xsig(0),
		x(3) => xsig(2),

		y(0,0) => ysig(0,0),
		--y(0,1) => ysig(0,1),
		y(1,0) => ysig(1,0),
		y(0,0) => ysig(0,0),
		y(1,1) => ysig(1,1)
		);
 
end arch;


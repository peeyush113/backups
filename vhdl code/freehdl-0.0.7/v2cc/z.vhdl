-----------------------------------------------------------
-- Example VHDL file
-- Just a dummy test file! Does not do anything useful!
-----------------------------------------------------------

entity ttt is 
 	-- Currently, no generics are supported
	port (i1 : inout integer; b1 : inout bit);
end ttt;

architecture arch of ttt is
begin
	i1 <= i1 + 1 after 10 ns;
	b1 <= not b1 after 10 ns;
end arch;

entity tveccomp is 
 	-- Currently, no generics are supported
	port (bvec : inout bit_vector(0 to 7));
end tveccomp;

architecture arch of tveccomp is
begin
	bvec <= (not bvec(0)) & bvec(1 to 6) & (not bvec(7)) after 20 ns;
end arch;



entity model is 
 	-- Currently, no generics are supported
	-- generic (g1 : bit := '0'; g2 : integer := 1000); 
	port (port_sig1 : inout integer; port_sig2 : bit);
end model;

-- This is a comment
architecture struct of model is
	constant zero : bit := '0';
	signal vec, vec2, vv1, vv2, vv3, yyy : bit_vector(0 to 7);
	signal aaa : bit_vector(3 downto 0) := "1010";
	signal bbb, ccc, ddd : bit_vector(0 to 3) := "1100";
	signal zzz, rvec : bit_vector(15 downto 0) := "1100110110110000";
	signal a0, a1, a3 : bit := zero;
	signal int1, int2, int3, int4 : integer;
	signal init_vec : bit_vector(7 downto 1) := (others => '1');
	signal zzzvec : bit_vector(8 downto 1) := (others => '1');

	type color is (red, yellow, green);
	type int_vec is array(0 to 3) of integer;
	type array2d is array(color) of int_vec;

	signal vec2d : array2d;
begin

 vvv: process (int3)
 begin
	int3 <= int3 + 1 after 10 ns;
 end process;

 int4 <= int4 + 2 after 10 ns;

 comp1: entity WORK.ttt
	port map(i1 => int1, b1 => vv3(0));
 
 comp2: entity WORK.ttt
	port map(int2, vv3(7));

 comp3: entity WORK.tveccomp
	port map(zzzvec);
 
 process
 begin
	if init_vec(5 downto 1)'event then
		a0 <= not a0 after 30 ns;
	end if;
	if init_vec(5 downto 1)'active and a0'active then
		a0 <= not a0 after 30 ns;
	end if;
	vec <= zzz(15 downto 8);
	ccc <= ccc(0 to 2) & '1';
	vec2 <= aaa & zzz(15 downto 12);
	port_sig1 <= port_sig1 + 1;
	if vec(3) = vec(2+2) then
		port_sig1 <= port_sig1 + 2;
	end if;
	for i in 0 to 7 loop
		yyy(i) <= vec(i);
	end loop;
	wait on a0;
 end process;

 p2: process
	constant const : integer := 1;
	variable intvar : integer := const;
	variable vecvar : bit_vector(0 to 7) := "11011011";
 begin
	vv1 <= "00000000";
	wait on a0;
	vv1 <= vecvar;
	wait on a0;
	vv1(0) <= '0';
	wait on a0;
	intvar := 0;
 end process;

 rot: process
 begin
   	rvec <= rvec(14 downto 0) & rvec(2**4-1) after 10 ns;
   	ddd <= ddd(3) & ddd(2) & ddd(1) & ddd(0) after 10 ns;
   	wait on rvec;
 end process;

 twodim_process: process
 begin
	vec2d <= (red => (others => -1), yellow => (others => 0), green => (others => 1));
	wait on vec2d;
	loop
		vec2d(red) <= vec2d(yellow) after 10 ns;
		vec2d(yellow) <= vec2d(green) after 10 ns;
		vec2d(green) <= vec2d(red) after 10 ns;
		wait on vec2d;
	end loop;
 end process;

end struct;


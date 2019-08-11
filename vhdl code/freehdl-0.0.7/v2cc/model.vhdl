-- testbench to test the adder 
entity model is 
end model;

-- This is a comment
architecture struct of model is
	signal asig, bsig, qsig : bit_vector(0 to 7) := (3 | 4 | 6 => '1', others => '0');
	signal clk : bit := '0';
	--signal x : integer :=8;
begin

 clk <= not clk after 10 ns;

 process
	variable var : integer;

	procedure proc is
		variable v : integer := 1;
	begin
		report "this is another test message!";
		var := var + v;
	end proc;
 begin	
	-- Generate some test vectors for the
	-- adder
	asig <= (not asig(7)) & asig(0 to 6);
	bsig <= asig(1 to 7) & (not bsig(1));
	report "this is a test message!";
	proc;
	wait until clk = '1';
 end process;

end struct;


library ieee;
use ieee.std_logic_1164.all;

entity model is 
end model;
architecture struct of model is
	signal clk : bit;
	signal clk2 : std_logic;
	type myarray is array(0 to 1, -1 to 3) of integer;
	subtype bvec_type is bit_vector(1 to 4);

    type UNSIGNED is array (NATURAL range <>) of STD_LOGIC;
    type SIGNED is array (NATURAL range <>) of STD_LOGIC;
	
function SHL(ARG: UNSIGNED; COUNT: UNSIGNED) return UNSIGNED is
	-- synopsys subpgm_id 358
	constant control_msb: INTEGER := COUNT'length - 1;
	variable control: UNSIGNED (control_msb downto 0);
	constant result_msb: INTEGER := ARG'length-1;
	subtype rtype is UNSIGNED (result_msb downto 0);
	variable result, temp: rtype;
    begin
	-- synopsys synthesis_off
--	if (control(0) = 'X') then
--	    result := rtype'(others => 'X');
--	    return result;
--	end if;
	-- synopsys synthesis_on
	result := ARG;
	for i in 0 to control_msb loop
	    if control(i) = '1' then
		temp := rtype'(others => '0');
		if 2**i <= result_msb then
		    temp(result_msb downto 2**i) := 
				    result(result_msb - 2**i downto 0);
		end if;
		result := temp;
	    end if;
	end loop;
	return result;
    end;

begin
 process 
	variable vec : bit_vector(7 downto 1);
 begin	
	vec(6 downto 1) := (others => '0');
	wait until clk = '1';
	if rising_edge(clk2) then
		clk <= not clk;
	end if;
 end process;

end struct;


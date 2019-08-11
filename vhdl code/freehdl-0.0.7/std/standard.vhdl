package standard is

    -- standard package as defined by LRM-93

    type BOOLEAN is ( FALSE, TRUE );	-- order is important for v2c to work
    type BIT is ( '0', '1' );

    type CHARACTER is (
		nul, soh, stx, etx, eot, enq, ack, bel, 
		bs,  ht,  lf,  vt,  ff,  cr,  so,  si, 
		dle, dc1, dc2, dc3, dc4, nak, syn, etb, 
		can, em,  sub, esc, fsp, gsp, rsp, usp, 

		' ', '!', '"', '#', '$', '%', '&', ''', 
		'(', ')', '*', '+', ',', '-', '.', '/', 
		'0', '1', '2', '3', '4', '5', '6', '7', 
		'8', '9', ':', ';', '<', '=', '>', '?', 

		'@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 
		'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 
		'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 
		'X', 'Y', 'Z', '[', '\', ']', '^', '_', 

		'`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 
		'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 
		'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 
		'x', 'y', 'z', '{', '|', '}', '~', del,

		c128, c129, c130, c131, c132, c133, c134, c135,
		c136, c137, c138, c139, c140, c141, c142, c143,
		c144, c145, c146, c147, c148, c149, c150, c151,
		c152, c153, c154, c155, c156, c157, c158, c159

		-- the character code for 160 is there (NBSP), 
		-- but prints as no char 
    );

    type SEVERITY_LEVEL is ( NOTE, WARNING, ERROR, FAILURE );
    
    type INTEGER is range -2147483648 to 2147483647;  -- 32 bits

    type REAL is range -1.0E307 to 1.0E307; 

    -- XXX - can't specify -9223372036854775808 as lower bound since
    --       9223372036854775808 is not representable and
    --       "-9223372036854775807-1" can not be calculated since it
    --       would be done with the integer code which allows only 32
    --       bits.
    type TIME is range -9223372036854775807 to 9223372036854775807 units
                                                      -- 64 bits (signed?)
	fs;
	ps  = 1000 fs;
	ns  = 1000 ps;
	us  = 1000 ns;
	ms  = 1000 us;
	sec = 1000 ms;
	min = 60 sec;
	hr  = 60 min;
    end units;

    subtype DELAY_LENGTH is TIME range 0fs to 9223372036854775807fs;

    function NOW return TIME;	-- impure

    subtype NATURAL is INTEGER range 0 to 2147483647;
    subtype POSITIVE is INTEGER range 1 to 2147483647;

    type STRING is array (POSITIVE range <>) of CHARACTER;
    type BIT_VECTOR is array (NATURAL range <>) of BIT;

    type FILE_OPEN_KIND is (
	READ_MODE,
	WRITE_MODE,
	APPEND_MODE
    );

    type FILE_OPEN_STATUS is (
	OPEN_OK,
	STATUS_ERROR,
	NAME_ERROR,
	MODE_ERROR
    );

    attribute FOREIGN : STRING;

end;

package math is

    constant pi : real := 3.141;

    function sqrt ( x : real ) return real;
    function exp ( x : real ) return real;

end;

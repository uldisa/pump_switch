#include <avr/pgmspace.h>
prog_char THINSS8[][8] PROGMEM =
{
	{ /*	32	' ' */
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000
	},
	{ /*	33	'!' */
		0b00010000,
		0b00010000,
		0b00010000,
		0b00010000,
		0b00010000,
		0b00000000,
		0b00010000,
		0b00000000
	},
	{ /*	34	'"' */
		0b00100100,
		0b00100100,
		0b00100100,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000
	},
	{ /*	35	'#' */
		0b00100100,
		0b00100100,
		0b01111110,
		0b00100100,
		0b01111110,
		0b00100100,
		0b00100100,
		0b00000000
	},
	{ /*	36	'$' */
		0b00011000,
		0b00111110,
		0b01000000,
		0b00111100,
		0b00000010,
		0b01111100,
		0b00011000,
		0b00000000
	},
	{ /*	37	'%' */
		0b00000000,
		0b01100010,
		0b01100100,
		0b00001000,
		0b00010000,
		0b00100110,
		0b01000110,
		0b00000000
	},
	{ /*	38	'&' */
		0b00110000,
		0b01001000,
		0b00110000,
		0b01010110,
		0b10001000,
		0b10001000,
		0b01110110,
		0b00000000
	},
	{ /*	39	''' */
		0b00010000,
		0b00010000,
		0b00100000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000
	},
	{ /*	40	'(' */
		0b00010000,
		0b00100000,
		0b01000000,
		0b01000000,
		0b01000000,
		0b00100000,
		0b00010000,
		0b00000000
	},
	{ /*	41	')' */
		0b00100000,
		0b00010000,
		0b00001000,
		0b00001000,
		0b00001000,
		0b00010000,
		0b00100000,
		0b00000000
	},
	{ /*	42	'*' */
		0b00000000,
		0b01000100,
		0b00111000,
		0b11111110,
		0b00111000,
		0b01000100,
		0b00000000,
		0b00000000
	},
	{ /*	43	'+' */
		0b00000000,
		0b00010000,
		0b00010000,
		0b01111100,
		0b00010000,
		0b00010000,
		0b00000000,
		0b00000000
	},
	{ /*	44	',' */
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00010000,
		0b00010000,
		0b00100000
	},
	{ /*	45	'-' */
		0b00000000,
		0b00000000,
		0b00000000,
		0b01111110,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000
	},
	{ /*	46	'.' */
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00010000,
		0b00010000,
		0b00000000
	},
	{ /*	47	'/' */
		0b00000000,
		0b00000010,
		0b00000100,
		0b00001000,
		0b00010000,
		0b00100000,
		0b01000000,
		0b00000000
	},
	{ /*	48	'0' */
		0b00111100,
		0b01000010,
		0b01000110,
		0b01001010,
		0b01010010,
		0b01100010,
		0b00111100,
		0b00000000
	},
	{ /*	49	'1' */
		0b00010000,
		0b00110000,
		0b01010000,
		0b00010000,
		0b00010000,
		0b00010000,
		0b01111100,
		0b00000000
	},
	{ /*	50	'2' */
		0b00111100,
		0b01000010,
		0b00000010,
		0b00001100,
		0b00110000,
		0b01000010,
		0b01111110,
		0b00000000
	},
	{ /*	51	'3' */
		0b00111100,
		0b01000010,
		0b00000010,
		0b00011100,
		0b00000010,
		0b01000010,
		0b00111100,
		0b00000000
	},
	{ /*	52	'4' */
		0b00001000,
		0b00011000,
		0b00101000,
		0b01001000,
		0b11111110,
		0b00001000,
		0b00011100,
		0b00000000
	},
	{ /*	53	'5' */
		0b01111110,
		0b01000000,
		0b01111100,
		0b00000010,
		0b00000010,
		0b01000010,
		0b00111100,
		0b00000000
	},
	{ /*	54	'6' */
		0b00011100,
		0b00100000,
		0b01000000,
		0b01111100,
		0b01000010,
		0b01000010,
		0b00111100,
		0b00000000
	},
	{ /*	55	'7' */
		0b01111110,
		0b01000010,
		0b00000100,
		0b00001000,
		0b00010000,
		0b00010000,
		0b00010000,
		0b00000000
	},
	{ /*	56	'8' */
		0b00111100,
		0b01000010,
		0b01000010,
		0b00111100,
		0b01000010,
		0b01000010,
		0b00111100,
		0b00000000
	},
	{ /*	57	'9' */
		0b00111100,
		0b01000010,
		0b01000010,
		0b00111110,
		0b00000010,
		0b00000100,
		0b00111000,
		0b00000000
	},
	{ /*	58	':' */
		0b00000000,
		0b00010000,
		0b00010000,
		0b00000000,
		0b00000000,
		0b00010000,
		0b00010000,
		0b00000000
	},
	{ /*	59	';' */
		0b00000000,
		0b00010000,
		0b00010000,
		0b00000000,
		0b00000000,
		0b00010000,
		0b00010000,
		0b00100000
	},
	{ /*	60	'<' */
		0b00001000,
		0b00010000,
		0b00100000,
		0b01000000,
		0b00100000,
		0b00010000,
		0b00001000,
		0b00000000
	},
	{ /*	61	'=' */
		0b00000000,
		0b00000000,
		0b01111110,
		0b00000000,
		0b00000000,
		0b01111110,
		0b00000000,
		0b00000000
	},
	{ /*	62	'>' */
		0b00010000,
		0b00001000,
		0b00000100,
		0b00000010,
		0b00000100,
		0b00001000,
		0b00010000,
		0b00000000
	},
	{ /*	63	'?' */
		0b00111100,
		0b01000010,
		0b00000010,
		0b00000100,
		0b00001000,
		0b00000000,
		0b00001000,
		0b00000000
	},
	{ /*	64	'@' */
		0b00111100,
		0b01000010,
		0b01011110,
		0b01010010,
		0b01011110,
		0b01000000,
		0b00111100,
		0b00000000
	},
	{ /*	65	'A' */
		0b00011000,
		0b00100100,
		0b01000010,
		0b01000010,
		0b01111110,
		0b01000010,
		0b01000010,
		0b00000000
	},
	{ /*	66	'B' */
		0b01111100,
		0b00100010,
		0b00100010,
		0b00111100,
		0b00100010,
		0b00100010,
		0b01111100,
		0b00000000
	},
	{ /*	67	'C' */
		0b00011100,
		0b00100010,
		0b01000000,
		0b01000000,
		0b01000000,
		0b00100010,
		0b00011100,
		0b00000000
	},
	{ /*	68	'D' */
		0b01111000,
		0b00100100,
		0b00100010,
		0b00100010,
		0b00100010,
		0b00100100,
		0b01111000,
		0b00000000
	},
	{ /*	69	'E' */
		0b01111110,
		0b00100010,
		0b00101000,
		0b00111000,
		0b00101000,
		0b00100010,
		0b01111110,
		0b00000000
	},
	{ /*	70	'F' */
		0b01111110,
		0b00100010,
		0b00101000,
		0b00111000,
		0b00101000,
		0b00100000,
		0b01110000,
		0b00000000
	},
	{ /*	71	'G' */
		0b00011100,
		0b00100010,
		0b01000000,
		0b01000000,
		0b01001110,
		0b00100010,
		0b00011110,
		0b00000000
	},
	{ /*	72	'H' */
		0b01000010,
		0b01000010,
		0b01000010,
		0b01111110,
		0b01000010,
		0b01000010,
		0b01000010,
		0b00000000
	},
	{ /*	73	'I' */
		0b00111000,
		0b00010000,
		0b00010000,
		0b00010000,
		0b00010000,
		0b00010000,
		0b00111000,
		0b00000000
	},
	{ /*	74	'J' */
		0b00001110,
		0b00000100,
		0b00000100,
		0b00000100,
		0b01000100,
		0b01000100,
		0b00111000,
		0b00000000
	},
	{ /*	75	'K' */
		0b01100010,
		0b00100100,
		0b00101000,
		0b00110000,
		0b00101000,
		0b00100100,
		0b01100011,
		0b00000000
	},
	{ /*	76	'L' */
		0b01110000,
		0b00100000,
		0b00100000,
		0b00100000,
		0b00100000,
		0b00100010,
		0b01111110,
		0b00000000
	},
	{ /*	77	'M' */
		0b01100011,
		0b01010101,
		0b01001001,
		0b01000001,
		0b01000001,
		0b01000001,
		0b01000001,
		0b00000000
	},
	{ /*	78	'N' */
		0b01100010,
		0b01010010,
		0b01001010,
		0b01000110,
		0b01000010,
		0b01000010,
		0b01000010,
		0b00000000
	},
	{ /*	79	'O' */
		0b00111100,
		0b01000010,
		0b01000010,
		0b01000010,
		0b01000010,
		0b01000010,
		0b00111100,
		0b00000000
	},
	{ /*	80	'P' */
		0b01111100,
		0b00100010,
		0b00100010,
		0b00111100,
		0b00100000,
		0b00100000,
		0b01110000,
		0b00000000
	},
	{ /*	81	'Q' */
		0b00111100,
		0b01000010,
		0b01000010,
		0b01000010,
		0b01001010,
		0b00111100,
		0b00000011,
		0b00000000
	},
	{ /*	82	'R' */
		0b01111100,
		0b00100010,
		0b00100010,
		0b00111100,
		0b00101000,
		0b00100100,
		0b01110010,
		0b00000000
	},
	{ /*	83	'S' */
		0b00111100,
		0b01000010,
		0b01000000,
		0b00111100,
		0b00000010,
		0b01000010,
		0b00111100,
		0b00000000
	},
	{ /*	84	'T' */
		0b01111111,
		0b01001001,
		0b00001000,
		0b00001000,
		0b00001000,
		0b00001000,
		0b00011100,
		0b00000000
	},
	{ /*	85	'U' */
		0b01000010,
		0b01000010,
		0b01000010,
		0b01000010,
		0b01000010,
		0b01000010,
		0b00111100,
		0b00000000
	},
	{ /*	86	'V' */
		0b01000001,
		0b01000001,
		0b01000001,
		0b01000001,
		0b00100010,
		0b00010100,
		0b00001000,
		0b00000000
	},
	{ /*	87	'W' */
		0b01000001,
		0b01000001,
		0b01000001,
		0b01001001,
		0b01001001,
		0b01001001,
		0b00110110,
		0b00000000
	},
	{ /*	88	'X' */
		0b01000001,
		0b00100010,
		0b00010100,
		0b00001000,
		0b00010100,
		0b00100010,
		0b01000001,
		0b00000000
	},
	{ /*	89	'Y' */
		0b01000001,
		0b00100010,
		0b00010100,
		0b00001000,
		0b00001000,
		0b00001000,
		0b00011100,
		0b00000000
	},
	{ /*	90	'Z' */
		0b01111111,
		0b01000010,
		0b00000100,
		0b00001000,
		0b00010000,
		0b00100001,
		0b01111111,
		0b00000000
	},
	{ /*	91	'[' */
		0b01111000,
		0b01000000,
		0b01000000,
		0b01000000,
		0b01000000,
		0b01000000,
		0b01111000,
		0b00000000
	},
	{ /*	92	'\' */
		0b10000000,
		0b01000000,
		0b00100000,
		0b00010000,
		0b00001000,
		0b00000100,
		0b00000010,
		0b00000000
	},
	{ /*	93	']' */
		0b01111000,
		0b00001000,
		0b00001000,
		0b00001000,
		0b00001000,
		0b00001000,
		0b01111000,
		0b00000000
	},
	{ /*	94	'^' */
		0b00010000,
		0b00101000,
		0b01000100,
		0b10000010,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000
	},
	{ /*	95	'_' */
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b11111111
	},
	{ /*	96	'`' */
		0b00010000,
		0b00010000,
		0b00001000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000
	},
	{ /*	97	'a' */
		0b00000000,
		0b00000000,
		0b00111100,
		0b00000010,
		0b00111110,
		0b01000010,
		0b00111111,
		0b00000000
	},
	{ /*	98	'b' */
		0b01100000,
		0b00100000,
		0b00100000,
		0b00101110,
		0b00110001,
		0b00110001,
		0b00101110,
		0b00000000
	},
	{ /*	99	'c' */
		0b00000000,
		0b00000000,
		0b00111100,
		0b01000010,
		0b01000000,
		0b01000010,
		0b00111100,
		0b00000000
	},
	{ /*	100	'd' */
		0b00000110,
		0b00000010,
		0b00000010,
		0b00111010,
		0b01000110,
		0b01000110,
		0b00111011,
		0b00000000
	},
	{ /*	101	'e' */
		0b00000000,
		0b00000000,
		0b00111100,
		0b01000010,
		0b01111110,
		0b01000000,
		0b00111100,
		0b00000000
	},
	{ /*	102	'f' */
		0b00001100,
		0b00010010,
		0b00010000,
		0b00111000,
		0b00010000,
		0b00010000,
		0b00111000,
		0b00000000
	},
	{ /*	103	'g' */
		0b00000000,
		0b00000000,
		0b00111101,
		0b01000010,
		0b01000010,
		0b00111110,
		0b00000010,
		0b01111100
	},
	{ /*	104	'h' */
		0b01100000,
		0b00100000,
		0b00101100,
		0b00110010,
		0b00100010,
		0b00100010,
		0b01100010,
		0b00000000
	},
	{ /*	105	'i' */
		0b00010000,
		0b00000000,
		0b00110000,
		0b00010000,
		0b00010000,
		0b00010000,
		0b00111000,
		0b00000000
	},
	{ /*	106	'j' */
		0b00000010,
		0b00000000,
		0b00000110,
		0b00000010,
		0b00000010,
		0b01000010,
		0b01000010,
		0b00111100
	},
	{ /*	107	'k' */
		0b01100000,
		0b00100000,
		0b00100100,
		0b00101000,
		0b00110000,
		0b00101000,
		0b00100110,
		0b00000000
	},
	{ /*	108	'l' */
		0b00110000,
		0b00010000,
		0b00010000,
		0b00010000,
		0b00010000,
		0b00010000,
		0b00111000,
		0b00000000
	},
	{ /*	109	'm' */
		0b00000000,
		0b00000000,
		0b01110110,
		0b01001001,
		0b01001001,
		0b01001001,
		0b01001001,
		0b00000000
	},
	{ /*	110	'n' */
		0b00000000,
		0b00000000,
		0b01011100,
		0b01100010,
		0b01000010,
		0b01000010,
		0b01000010,
		0b00000000
	},
	{ /*	111	'o' */
		0b00000000,
		0b00000000,
		0b00111100,
		0b01000010,
		0b01000010,
		0b01000010,
		0b00111100,
		0b00000000
	},
	{ /*	112	'p' */
		0b00000000,
		0b00000000,
		0b01101100,
		0b00110010,
		0b00110010,
		0b00101100,
		0b00100000,
		0b01110000
	},
	{ /*	113	'q' */
		0b00000000,
		0b00000000,
		0b00110110,
		0b01001100,
		0b01001100,
		0b00110100,
		0b00000100,
		0b00001110
	},
	{ /*	114	'r' */
		0b00000000,
		0b00000000,
		0b01101100,
		0b00110010,
		0b00100010,
		0b00100000,
		0b01110000,
		0b00000000
	},
	{ /*	115	's' */
		0b00000000,
		0b00000000,
		0b00111110,
		0b01000000,
		0b00111100,
		0b00000010,
		0b01111100,
		0b00000000
	},
	{ /*	116	't' */
		0b00010000,
		0b00010000,
		0b01111100,
		0b00010000,
		0b00010000,
		0b00010010,
		0b00001100,
		0b00000000
	},
	{ /*	117	'u' */
		0b00000000,
		0b00000000,
		0b01000010,
		0b01000010,
		0b01000010,
		0b01000110,
		0b00111010,
		0b00000000
	},
	{ /*	118	'v' */
		0b00000000,
		0b00000000,
		0b01000001,
		0b01000001,
		0b00100010,
		0b00010100,
		0b00001000,
		0b00000000
	},
	{ /*	119	'w' */
		0b00000000,
		0b00000000,
		0b01000001,
		0b01001001,
		0b01001001,
		0b01001001,
		0b00110110,
		0b00000000
	},
	{ /*	120	'x' */
		0b00000000,
		0b00000000,
		0b01000100,
		0b00101000,
		0b00010000,
		0b00101000,
		0b01000100,
		0b00000000
	},
	{ /*	121	'y' */
		0b00000000,
		0b00000000,
		0b01000010,
		0b01000010,
		0b01000010,
		0b00111110,
		0b00000010,
		0b01111100
	},
	{ /*	122	'z' */
		0b00000000,
		0b00000000,
		0b01111100,
		0b00001000,
		0b00010000,
		0b00100000,
		0b01111100,
		0b00000000
	},
	{ /*	123	'{' */
		0b00001100,
		0b00010000,
		0b00010000,
		0b01100000,
		0b00010000,
		0b00010000,
		0b00001100,
		0b00000000
	},
	{ /*	124	'|' */
		0b00010000,
		0b00010000,
		0b00010000,
		0b00000000,
		0b00010000,
		0b00010000,
		0b00010000,
		0b00000000
	},
	{ /*	125	'}' */
		0b00110000,
		0b00001000,
		0b00001000,
		0b00000110,
		0b00001000,
		0b00001000,
		0b00110000,
		0b00000000
	},
	{ /*	126	'~' */
		0b00110010,
		0b01001100,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000
	},
	{ /*	127	'' */
		0b00000000,
		0b00001000,
		0b00010100,
		0b00100010,
		0b01000001,
		0b01000001,
		0b01111111,
		0b00000000
	}
};
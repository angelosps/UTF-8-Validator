# :symbols: UTF-8-Validator

Project 2 for the course "Introduction to Programming" in Semester 1 @ University of Athens.   
This project is about checking if characters passed by the input are following the UTF-8 encoding rules.  
Reference for UTF-8 encoding: https://en.wikipedia.org/wiki/UTF-8.  
The program checks the characters read from the input and finds how many of them are ASCII characters and how many of them are multi-byte UTF-8 characters. In case a sequence of bytes that has been read it is not valid according to UTF-8 encoding rules, the appropriate error message is returned.

Here is an example of running the program with the included test cases:

``` bash

$ ./utf8validate < elytis_mon.txt
Found 31 ASCII and 134 multi-byte UTF-8 characters.
$ ./utf8validate < elytis_pol.txt
Found 31 ASCII and 134 multi-byte UTF-8 characters.
$ ./utf8validate < icaneatglass.txt
Found 6988 ASCII and 1955 multi-byte UTF-8 characters. 
$ ./utf8validate < utf8_correct.txt
Found 3283 ASCII and 3682 multi-byte UTF-8 characters. 
$ ./utf8validate < utf8_invalid_codepoint_1.txt 
Invalid UTF-8 code point: U+D800
$ ./utf8validate < utf8_invalid_codepoint_2.txt 
Invalid UTF-8 code point: U+123456
$ ./utf8validate < utf8_invalid_header_byte.txt 
Invalid UTF-8 header byte: 0xFF
$ ./utf8validate < utf8_invalid_tail_byte.txt
Invalid UTF-8 tail byte: 0x00
$ ./utf8validate < utf8_oversized_codepoint_1.txt 
Oversized UTF-8 code point: U+0028
$ ./utf8validate < utf8_oversized_codepoint_2.txt 
Oversized UTF-8 code point: U+1262
$

```

It is included the statement of the project in Greek which provides a more extensive description of the UTF-8 encoding rules and the project.

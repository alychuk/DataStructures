echo "TEST CASES"
echo -e '\n'
echo "Stack Test: "
./test6 << STACKTEST
+x
+x
-
-
-
+x
E
F
C
E
F
Q
STACKTEST
echo -e '\n'
echo "Postfix Test Cases 0-4"
echo -e '\n'
echo "CASE 0"
echo "Infix Notation: (3+4)*(5/2)"
echo "Postfix Notation: 34+52/*"
./postfix << POSTFIXTEST0
3 4 + 5 2 / *
POSTFIXTEST0
echo -e '\n'
echo "CASE 1"
echo "Infix Notation: (3*4)+(5-2)"
echo "Postfix Notation: 34*52-+"
./postfix << POSTFIXTEST1
3 4 * 5 2 - +
POSTFIXTEST1
echo -e '\n'
echo "CASE 2"
echo "Infix Notation: (9-4)/(3*2)"
echo "Postfix Notation: 94-32*/"
./postfix << POSTFIXTEST2
9 4 - 3 2 * /
POSTFIXTEST2
echo -e '\n'
echo "CASE 3"
echo "Infix Notation: (3*4*7)-(8/2)+(4+3)"
echo "Postfix Notation: 34*7*82/-43++"
./postfix << POSTFIXTEST3
3 4 * 7 * 8 2 / - 4 3 + +
POSTFIXTEST3
echo -e '\n'
echo "CASE 4"
echo "Infix Notation: ((8+8)/2)+((6-3)*4*7)"
echo "Postfix Notation: 88+2/63-4*7*+"
./postfix << POSTFIXTEST4
8 8 + 2 / 6 3 - 4 * 7 * +
POSTFIXTEST4
echo -e '\n'
echo "Delimiter Test Cases 0-4"
echo -e '\n'
echo "CASES"
echo -e "..0..(3+4)*(5/2)\n..1..(3*4*7)-(8/2)+(4+3)\n..2..((8+8)/2)+((6-3)*4*7)\n..3..((((())\n..4..(()))))"
./delimiters << DELIMITERSTEST0
(3+4)*(5/2)
(3*4*7)-(8/2)+(4+3)
((8+8)/2)+((6-3)*4*7)
((((())
(()))))
DELIMITERSTEST0

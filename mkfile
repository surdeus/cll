<mkconfig
<$MKINCDIR/cabuild
test:V:
	$CC -o test $INCS $CFILES test.c  && ./test

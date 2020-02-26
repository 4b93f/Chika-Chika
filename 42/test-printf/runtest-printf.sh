GREEN='\033[0;32m'
DARK_BLUE='\e[1;34m'
RED='\x1B[31m'
BLUE='\e[96m'
NC='\033[0m'
i=0
success=0
error=0

# $1 = text, $2 = test number
test()
{
	printf "$1" >> test-printf/result.log
	test-printf/test.out $2 > test-printf/original_output
	echo $? >> test-printf/original_output
	sh test-printf/timeout.sh 1 test-printf/test.out $2 user > test-printf/user_output 2> /dev/null
	ret=$(echo $?)
	echo $ret >> test-printf/user_output
	if diff "test-printf/original_output" "test-printf/user_output" >> /dev/null
	then
		if [ $error -eq 1 ]
		then
			printf "\n"
		fi
    	printf "${GREEN}OK ${NC}"
    	printf "${GREEN}OK ${NC}\n" >> test-printf/result.log
		((success++))
		error=0
	else
    	printf "\n${RED}$1"
		if [ $ret -eq 142 ] #timeout
		then
			printf "${RED}TIMEOUT${NC}"
			printf "${RED}TIMEOUT${NC}\n" >> test-printf/result.log
		else
			printf "${RED}FAILED${NC}"
			printf "${RED}FAILED${NC}\n" >> test-printf/result.log
		fi
		error=1
	fi
	((i++))
}

rm test-printf/result.log
make all
make bonus
gcc -Wall -Wextra -Werror -Wformat=0 test-printf/test-main.c libftprintf.a -o test-printf/test.out
printf "\n${BLUE}[I - Tests with *]${NC}\n"
test "$i - (\"%%*d\", 0, 42) : ${NC}" $i 
test "$i - (\"%%*d\", 0, 0) : ${NC}" $i 
test "$i - (\"%%*d\", 10, 42) : ${NC}" $i 
test "$i - (\"%%*d\", -10, 42) : ${NC}" $i 
test "$i - (\"%%0*d\", -10, 42) : ${NC}" $i 
test "$i - (\"%%0*d\", 10, 42) : ${NC}" $i 
test "$i - (\"%%0*d\", 10, -42) : ${NC}" $i 
test "$i - (\"%%0*d\", 0, 42) : ${NC}" $i 
test "$i - (\"%%0*d\", 10, 0) : ${NC}" $i 
test "$i - (\"%%0*d\", -10, 0) : ${NC}" $i 
test "$i - (\"%%*d\", 010, 42) : ${NC}" $i 
test "$i - (\"%%*s\", 10, \"Hello\") : ${NC}" $i 
test "$i - (\"%%*s\", -10, \"Hello\") : ${NC}" $i 
test "$i - (\"%%-*d\", 10, 42) : ${NC}" $i 
test "$i - (\"%%-*d\", -10, 42) : ${NC}" $i 
test "$i - (\"%%-*d\", -10, -42) : ${NC}" $i 
test "$i - (\"%%.*d\", 0, 42) : ${NC}" $i 
test "$i - (\"%%.*d\", 10, 42) : ${NC}" $i 
test "$i - (\"%%.*d\", -10, 42) : ${NC}" $i 
test "$i - (\"%%.*d\", 0, 0) : ${NC}" $i 
test "$i - (\"%%.*d\", 10, 0) : ${NC}" $i 
test "$i - (\"%%.*d\", -10, 0) : ${NC}" $i 
test "$i - (\"%%.*d\", -0, 0) : ${NC}" $i 
test "$i - (\"%%.*d\", -0, 42) : ${NC}" $i 
test "$i - (\"%%.*d\", -0, -42) : ${NC}" $i 
test "$i - (\"%%.*s\", -3, \"Hello\") : ${NC}" $i 
test "$i - (\"%%10.*d\", 10, 42) : ${NC}" $i 
test "$i - (\"%%*.10d\", 10, 42) : ${NC}" $i 
test "$i - (\"%%*.*d\", 0, 0, 0) : ${NC}" $i 
test "$i - (\"%%*.*d\", 0, 0, 42) : ${NC}" $i 
test "$i - (\"%%*.*d\", 0, 0, -42) : ${NC}" $i 
test "$i - (\"%%*.*d\", 0, 5, 0) : ${NC}" $i 
test "$i - (\"%%*.*d\", 0, -5, 0) : ${NC}" $i 
test "$i - (\"%%*.*d\", 5, 0, 0) : ${NC}" $i 
test "$i - (\"%%*.*d\", -5, 0, 0) : ${NC}" $i 
test "$i - (\"%%*.*d\", 5, 5, 0) : ${NC}" $i 
test "$i - (\"%%*.*s\", 0, 0, \"Hello\") : ${NC}" $i 
test "$i - (\"%%*.*s\", 0, 0, \"Hello\") : ${NC}" $i 
test "$i - (\"%%*.*s\", 0, 0, \"Hello\") : ${NC}" $i 
test "$i - (\"%%*.*s\", 0, 5, \"Hello\") : ${NC}" $i 
test "$i - (\"%%*.*s\", 0, -5, \"Hello\") : ${NC}" $i 
test "$i - (\"%%*.*s\", 5, 0, \"Hello\") : ${NC}" $i 
test "$i - (\"%%*.*s\", -5, 0, \"Hello\") : ${NC}" $i 
test "$i - (\"%%*.*s\", 5, 5, \"Hello\") : ${NC}" $i 
printf "\n\n${DARK_BLUE}Result [$success/$i]${NC}"

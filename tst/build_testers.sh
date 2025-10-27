set -ex
if [ -e ../libft.a ]
then
	cc vector_tester.c ../libft.a -Wall -Wextra -Werror -o vector_tester
	cc arena_tester.c ../libft.a -Wall -Wextra -Werror -o arena_tester
	cc gnl_tester.c ../libft.a -Wall -Wextra -Werror -o gnl_tester
else
	cd ..
	make
	cd tst/
	cc vector_tester.c ../libft.a -Wall -Wextra -Werror -o vector_tester
	cc arena_tester.c ../libft.a -Wall -Wextra -Werror -o arena_tester
	cc gnl_tester.c ../libft.a -Wall -Wextra -Werror -o gnl_tester
fi

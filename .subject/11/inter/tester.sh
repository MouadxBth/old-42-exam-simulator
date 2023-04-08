# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2021/12/30 17:01:55 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='inter.c'


index=0

if [ -e traceback ]
then
    rm traceback
fi

cd .system/verif
gcc -Wall -Wextra -Werror  -o source $FILE
./source | cat -e > sourcexam       #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $FILE
}  &>../.system/verif/traceback
{
./final | cat -e > finalexam        #TESTING
mv finalexam ../.system/verif/
rm final
}  &>/dev/null
cd ../.system/verif
DIFF=$(diff sourcexam finalexam)
echo "" >> traceback
if [ "$DIFF" != "" ]
then
		index=$(($index + 1))
		cat sourcexam >> traceback
		if [ -e finalexam ]
		then
		cat finalexam >> traceback
		else
		echo "" >> traceback
		fi
		echo "-------" >> traceback
fi
rm finalexam



gcc -Wall -Wextra -Werror  -o source $FILE
./source "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $FILE
./final "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e > finalexam     #TESTING
mv finalexam ../.system/verif/
rm final
}  &>/dev/null
cd ../.system/verif
DIFF=$(diff sourcexam finalexam)
if [ "$DIFF" != "" ]
then
		index=$(($index + 1))
		cat sourcexam >> traceback
		if [ -e finalexam ]
		then
		cat finalexam >> traceback
		else
		echo "" >> traceback
		fi
		echo "-------" >> traceback
fi
rm finalexam



gcc -Wall -Wextra -Werror  -o source $FILE
./source ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $FILE
./final ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e > finalexam     #TESTING
mv finalexam ../.system/verif/
rm final
}  &>/dev/null
cd ../.system/verif
DIFF=$(diff sourcexam finalexam)
if [ "$DIFF" != "" ]
then
		index=$(($index + 1))
		cat sourcexam >> traceback
		if [ -e finalexam ]
		then
		cat finalexam >> traceback
		else
		echo "" >> traceback
		fi
		echo "-------" >> traceback
fi
rm finalexam




gcc -Wall -Wextra -Werror  -o source $FILE
./source "zz sent le poney" | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $FILE
./final "zz sent le poney" | cat -e > finalexam     #TESTING
mv finalexam ../.system/verif/
rm final
}  &>/dev/null
cd ../.system/verif
DIFF=$(diff sourcexam finalexam)
if [ "$DIFF" != "" ]
then
		index=$(($index + 1))
		cat sourcexam >> traceback
		if [ -e finalexam ]
		then
		cat finalexam >> traceback
		else
		echo "" >> traceback
		fi
		echo "-------" >> traceback
fi
rm finalexam




gcc -Wall -Wextra -Werror  -o source $FILE
./source "rien" "cette phrase ne cache rien" | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $FILE
./final "rien" "cette phrase ne cache rien" | cat -e > finalexam     #TESTING
mv finalexam ../.system/verif/
rm final
}  &>/dev/null
cd ../.system/verif
DIFF=$(diff sourcexam finalexam)
if [ "$DIFF" != "" ]
then
		index=$(($index + 1))
		cat sourcexam >> traceback
		if [ -e finalexam ]
		then
		cat finalexam >> traceback
		else
		echo "" >> traceback
		fi
		echo "-------" >> traceback
fi
rm finalexam

gcc -Wall -Wextra -Werror  -o source $FILE
./source "AAAAaaaaaaaaAa" "test" | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $FILE
./final "AAAAaaaaaaaaAa" "test" | cat -e > finalexam     #TESTING
mv finalexam ../.system/verif/
rm final
}  &>/dev/null
cd ../.system/verif
DIFF=$(diff sourcexam finalexam)
if [ "$DIFF" != "" ]
then
		index=$(($index + 1))
		cat sourcexam >> traceback
		if [ -e finalexam ]
		then
		cat finalexam >> traceback
		else
		echo "" >> traceback
		fi
		echo "-------" >> traceback
fi
rm finalexam











if [ $index -eq 0 ]
then
	touch passed
fi
{
mv traceback ../../traceback
}	&>/dev/null
rm sourcexam

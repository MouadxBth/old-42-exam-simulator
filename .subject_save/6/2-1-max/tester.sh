# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2021/07/02 20:05:26 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='max.c'
MAIN='main.c'
MAIN1='../.system/verif/main.c'

index=0

if [ -e traceback ]
then
    rm traceback
fi

cd .system/verif
gcc -o source $FILE $MAIN
./source "1" "3" "212121" | cat -e > sourcexam       #TESTING
rm source
cd ../../rendu
{
gcc -o final $FILE $MAIN1
}  &>../.system/verif/traceback
{
./final "1" "3" "212121" | cat -e > finalexam        #TESTING
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
		echo '\n' >> traceback
		if [ -e finalexam ]
		then
		cat finalexam >> traceback
		else
		echo "" >> traceback
		fi
		echo '\n' >> traceback
		echo "-------" >> traceback
fi
rm finalexam



gcc -o source $FILE $MAIN
./source "1" "3" "524242432423423432" | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -o final $FILE $MAIN1
./final "1" "3" "524242432423423432" | cat -e > finalexam     #TESTING
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
		echo '\n' >> traceback
		if [ -e finalexam ]
		then
		cat finalexam >> traceback
		else
		echo "" >> traceback
		fi
		echo '\n' >> traceback
		echo "-------" >> traceback
fi

gcc -o source $FILE $MAIN
./source "-2" "-3" "-3" | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -o final $FILE $MAIN1
./final "-2" "-3" "-3" | cat -e > finalexam     #TESTING
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
		echo '\n' >> traceback
		if [ -e finalexam ]
		then
		cat finalexam >> traceback
		else
		echo "" >> traceback
		fi
		echo '\n' >> traceback
		echo "-------" >> traceback
fi

gcc -o source $FILE $MAIN
./source "-5" "-3" "-3" | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -o final $FILE $MAIN1
./final "-5" "-3" "-3" | cat -e > finalexam     #TESTING
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
		echo '\n' >> traceback
		if [ -e finalexam ]
		then
		cat finalexam >> traceback
		else
		echo "" >> traceback
		fi
		echo '\n' >> traceback
		echo "-------" >> traceback
fi




if [ $index -eq 0 ]
then
	touch passed
fi
{
mv traceback ../../traceback
}	&>/dev/null
rm sourcexam

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2021/07/02 20:09:38 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='wdmatch.c'
MAIN='main.c'
MAIN1='../.system/verif/main.c'

index=0

if [ -e traceback ]
then
    rm traceback
fi

cd .system/verif
gcc -o source $FILE $MAIN
./source  | cat -e > sourcexam       #TESTING
rm source
cd ../../rendu
{
gcc -o final $FILE $MAIN1
}  &>../.system/verif/traceback
{
./final  | cat -e > finalexam        #TESTING
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
./source "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -o final $FILE $MAIN1
./final "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e > finalexam     #TESTING
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
./source "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -o final $FILE $MAIN1
./final "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e > finalexam     #TESTING
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
./source "faya" "fgvvfdxcacpolhyghbred" | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -o final $FILE $MAIN1
./final "faya" "fgvvfdxcacpolhyghbred" | cat -e > finalexam     #TESTING
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
./source "faya" "fgvvfdxcacpolhyghbreda" | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -o final $FILE $MAIN1
./final "faya" "fgvvfdxcacpolhyghbreda" | cat -e > finalexam     #TESTING
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

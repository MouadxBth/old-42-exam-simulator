userpost="user=$LOGNAME"
{
exo=$(ls .system/verif/*.c)
} &>/dev/null
usingpost="using=SUCCESS>$exo"
date=$(date '+%F_%H:%M:%S')
time="time=$date"

curl -X POST -F $userpost -F $usingpost -F $time https://user.grademe.fr/index.php > /dev/null 2>&1

	rm -rf .system/verif/*
	{
	mkdir .system/saves
	mkdir success
	cp -r rendu/* success/
	} &>/dev/null

	rm -rf rendu/
	{
		rm -rf trace
	}	&>/dev/null
	rm -rf subject.fr.txt subject.en.txt
	{
		&>/dev/null
	}

## When a level is success, we delete files

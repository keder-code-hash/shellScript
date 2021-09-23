echo "enter a num: "
read num
res=$(($num%2))

if [ $res -eq 0 ]
then
	echo "even"
else
	echo "odd"
fi

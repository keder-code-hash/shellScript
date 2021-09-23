echo "enter the number: "
read num
read num1

while [ $num -le $num1 ]
do
	temp1=1
	div=0

	while [ $temp1 -le $num ]
	do
		rem=$(($num%$temp1))
		if [ $rem -eq 0 ]
		then
			div=$(($div+1))
		fi
		temp1=$(($temp1+1))
	done

	if [ $div -eq 2 ]
	then
		echo $num
	fi


	num=$(($num+1))
done



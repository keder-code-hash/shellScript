echo "enter the first number"
read num1
echo "enter the second number"
read num2
echo "enter the third number"
read num3



if [ $num1 -gt $num2 ]
then 
	if [ $num1 -gt $num3 ]
	then 
		echo "greater number is: "$num1
	else
		echo "greater number is: "$num3
	fi
else 
	if [ $num2 -gt $num3 ]
	then 
		echo "greater number is: "$num2
	else
		echo "greater number is: "$num3
	fi
fi
	


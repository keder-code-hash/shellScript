read num1
read num2
read op

case "$op" in
	1) echo $(($num1+$num2))
		;;
	2) pSub=0
	   if [ $num1 -gt $num2 ]
	   then
	   		pSub=$(($num1-$num2))
	   else
	   		pSub=$(($num2-$num1))
	   fi
	   echo $pSub
	    ;;
	3) echo $(($num1*$num2))
		;;
	4) echo $(($num1/$num2))
		;;
	*) echo "error"
		;;
esac
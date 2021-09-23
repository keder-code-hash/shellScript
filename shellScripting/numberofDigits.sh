echo "enter the number"
read num
sum=0
while [ $num -gt 0 ]
do
	sum=$(($sum+$(($num%10))))
	num=$(( $num/10 ))

done
echo $sum
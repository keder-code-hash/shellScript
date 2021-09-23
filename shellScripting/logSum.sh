read num
sum=0
i=1

while [ $i -le $num ]
do
	a=`echo "scale=3;l($i)/l(10)"|bc -l`
	# echo $a
	sum=`echo "scale=3;$sum+$a"|bc -l`
	# echo "hii"
	i=$(($i+1))
done
echo $sum
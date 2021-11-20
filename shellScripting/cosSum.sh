pi=`echo "scale=3;(22)/(7)"|bc -l`
echo $pi
index=0.2
sum=0
bound=`echo "scale=3;(2*$pi)"|bc -l`
# while [ $index -le $bound ]
# do
	# res=`echo "scale=3;c($index)/($index)"|bc -l`
	# sum=`echo "scale=3;($sum+$res)"|bc -l`
	# index=`echo "scale=3;($index+0.2)"|bc -l`
# done
# echo $pi


for i in $(seq $index 0.2 $bound)
do
	# echo $i
	# echo `echo "scale=3;c($i)"|bc -l`
	res=`echo "scale=3;c($i)"|bc -l`
	r=`echo "scale=3;($res/$i)"|bc -l`
	sum=`echo "scale=3;($sum+$res)"|bc -l`
done

echo $sum
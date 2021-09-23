echo "enter length"
read l
echo "enter Breadth"
read b
ar=$(($l*$b))
p=$((2*($l+$b)))
echo "area=" $ar
echo "perimeter=" $p

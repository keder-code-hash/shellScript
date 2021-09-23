read -p "Enter degree fahrenheit temperature: " fahrenheit
celsius=$(echo "scale=4; (5/9) * ($fahrenheit - 32)" | bc)
echo "$fahrenheit F degree fahrenheit is equal to $celsius C"
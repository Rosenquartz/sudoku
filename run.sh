a=${1%.*} &&
g++ $1 -o $a.out -g &&
./$a.out
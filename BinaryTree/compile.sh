# !/bin/bash
out=$1
outfile=${out%%.*}
g++ -std=c++11 -g -o $outfile $1 $2
chmod a+x $outfile
$(pwd)/$outfile

#!/bin/bash
# To redirect the results in a file
# You can run as ./runAll.sh 2> output.txt
# Check Statistics like grep "real" output.txt

arraySize=( 1 2 4 8 16 32 64 128 256 512 1024 1500 )
methods=( 0 1 )
perfStat=( "instructions:u,cycles:u"  "cache-references:u,cache-misses:u" )

gcc -mavx2 -O3 AVX2_char_count_std.c -o AVX2_char_count_std.out
for i in "${methods[@]}" 
	do 
		for ii in "${arraySize[@]}"
			do
			for iii in "${perfStat[@]}"	
				do
				for runs in {1..12}
					do
						>&2 echo time ./AVX2_char_count_std.out $i $ii
						 time ./AVX2_char_count_std.out $i $ii
					done
				done
			done
	done

for i in "${methods[@]}" 
	do 
	for ii in "${arraySize[@]}"
		do
		for runs in {1..12}
			do
			for iii in "${perfStat[@]}"	
				do
					echo perf stat -e $iii ./AVX2_char_count_std.out $i $ii
					perf stat  ./AVX2_char_count_std.out $i $ii
			done
		done
	done
done

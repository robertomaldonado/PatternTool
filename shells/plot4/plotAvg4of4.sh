#!/bin/sh

#grep "default_1.txt" default_1.txtplot.txt > global.dat

grep "default_2.txt" ../../files/default_2.txtplot.txt >> global.dat

grep "default_3.txt" ../../files/default_3.txtplot.txt >> global.dat

grep "default_4.txt" ../../files/default_4.txtplot.txt >> global.dat

#grep "default_5.txt" ../../files/default_5.txtplot.txt >> global.dat

grep "OBS " global.dat | awk '{s+=$48}END{printf "%.0f %.0f\n" ,1 , (s/4)}' > estadisticaGlobal.dat
grep "OAA " global.dat | awk '{s+=$50}END{printf "%.0f %.0f\n" ,2 , (s/4)}' >> estadisticaGlobal.dat
grep "ONS " global.dat | awk '{s+=$52}END{printf "%.0f %.0f\n" ,3 , (s/4)}' >> estadisticaGlobal.dat
grep "ODS " global.dat | awk '{s+=$54}END{printf "%.0f %.0f\n" ,4 , (s/4)}' >> estadisticaGlobal.dat

grep "OHO " global.dat | awk '{s+=$56}END{printf "%.0f %.0f\n" ,5 , (s/4)}' >> estadisticaGlobal.dat
grep "ONP " global.dat | awk '{s+=$58}END{printf "%.0f %.0f\n" ,6 , (s/4)}' >> estadisticaGlobal.dat
grep "OVD " global.dat | awk '{s+=$60}END{printf "%.0f %.0f\n" ,7 , (s/4)}' >> estadisticaGlobal.dat
grep "OPS " global.dat | awk '{s+=$62}END{printf "%.0f %.0f\n" ,8 , (s/4)}' >> estadisticaGlobal.dat
grep "OUS " global.dat | awk '{s+=$64}END{printf "%.0f %.0f\n" ,9 , (s/4)}' >> estadisticaGlobal.dat


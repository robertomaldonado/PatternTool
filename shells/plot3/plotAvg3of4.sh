#!/bin/sh

#grep "default_1.txt" default_1.txtplot.txt > global.dat

grep "default_2.txt" ../../files/default_2.txtplot.txt >> global.dat

grep "default_3.txt" ../../files/default_3.txtplot.txt >> global.dat

grep "default_4.txt" ../../files/default_4.txtplot.txt >> global.dat

#grep "default_5.txt" ../../files/default_5.txtplot.txt >> global.dat

#Si falla verificar los indices de valores enteros
grep "GPO " global.dat | awk '{s+=$36}END{printf "%.0f %.0f\n" ,1 , (s/4)}' > estadisticaGlobal.dat
grep "GPC " global.dat | awk '{s+=$38}END{printf "%.0f %.0f\n" ,2 , (s/4)}' >> estadisticaGlobal.dat
grep "GCO " global.dat | awk '{s+=$40}END{printf "%.0f %.0f\n" ,3 , (s/4)}' >> estadisticaGlobal.dat
grep "GCC " global.dat | awk '{s+=$42}END{printf "%.0f %.0f\n" ,4 , (s/4)}' >> estadisticaGlobal.dat

grep "GBO " global.dat | awk '{s+=$44}END{printf "%.0f %.0f\n" ,5 , (s/4)}' >> estadisticaGlobal.dat
grep "GBC " global.dat | awk '{s+=$46}END{printf "%.0f %.0f\n" ,6 , (s/4)}' >> estadisticaGlobal.dat


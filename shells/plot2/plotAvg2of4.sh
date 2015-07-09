#!/bin/sh

#grep "default_1.txt" default_1.txtplot.txt > global.dat

grep "default_2.txt" ../../files/default_2.txtplot.txt >> global.dat

grep "default_3.txt" ../../files/default_3.txtplot.txt >> global.dat

grep "default_4.txt" ../../files/default_4.txtplot.txt >> global.dat

#grep "default_5.txt" ../../files/default_5.txtplot.txt >> global.dat

#Si falla verificar los indices de valores enteros
grep "MPS " global.dat | awk '{s+=$20}END{printf "%.0f %.0f\n" ,1 , (s/3)}' > estadisticaGlobal.dat
grep "MMS " global.dat | awk '{s+=$22}END{printf "%.0f %.0f\n" ,2 , (s/3)}' >> estadisticaGlobal.dat
grep "MTS " global.dat | awk '{s+=$24}END{printf "%.0f %.0f\n" ,3 , (s/3)}' >> estadisticaGlobal.dat
grep "MMO " global.dat | awk '{s+=$26}END{printf "%.0f %.0f\n" ,4 , (s/3)}' >> estadisticaGlobal.dat

grep "MEQ " global.dat | awk '{s+=$28}END{printf "%.0f %.0f\n" ,5 , (s/3)}' >> estadisticaGlobal.dat
grep "MGR " global.dat | awk '{s+=$30}END{printf "%.0f %.0f\n" ,6 , (s/3)}' >> estadisticaGlobal.dat
grep "MLR " global.dat | awk '{s+=$32}END{printf "%.0f %.0f\n" ,7 , (s/3)}' >> estadisticaGlobal.dat
grep "MDN " global.dat | awk '{s+=$34}END{printf "%.0f %.0f\n" ,8 , (s/3)}' >> estadisticaGlobal.dat


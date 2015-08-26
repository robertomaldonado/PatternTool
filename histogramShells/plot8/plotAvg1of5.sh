#!/bin/sh

#grep "default_1.txt" default_1.txtplot.txt > global.dat

grep "default_2.txt" ../../files/default_2.txtplot_totales.txt >> global.dat

grep "default_3.txt" ../../files/default_3.txtplot_totales.txt >> global.dat

grep "default_4.txt" ../../files/default_4.txtplot_totales.txt >> global.dat

#grep "default_5.txt" ../../files/default_5.txtplot_tildes.txt >> global.dat

#grep "default_6.txt" ../../files/default_6.txtplot_tildes.txt >> global.dat

grep "TNMQ " global.dat | awk '{s+=$18}END{printf "%.0f %.4f\n" ,1 , (s/3)}' > estadisticaGlobal.dat
grep "TNME " global.dat | awk '{s+=$20}END{printf "%.0f %.4f\n" ,2 , (s/3)}' >> estadisticaGlobal.dat
grep "TNE " global.dat | awk '{s+=$22}END{printf "%.0f %.4f\n" ,3 , (s/3)}' >> estadisticaGlobal.dat
grep "TNWAP " global.dat | awk '{s+=$24}END{printf "%.0f %.4f\n" ,4 , (s/3)}' >> estadisticaGlobal.dat
grep "TNK1 " global.dat | awk '{s+=$26}END{printf "%.0f %.4f\n" ,5 , (s/3)}' >> estadisticaGlobal.dat
grep "TNK2 " global.dat | awk '{s+=$28}END{printf "%.0f %.4f\n" ,6 , (s/3)}' >> estadisticaGlobal.dat
grep "TNK3 " global.dat | awk '{s+=$30}END{printf "%.0f %.4f\n" ,7 , (s/3)}' >> estadisticaGlobal.dat
grep "TNCBS " global.dat | awk '{s+=$32}END{printf "%.0f %.4f\n" ,8 , (s/3)}' >> estadisticaGlobal.dat
grep "TNCAS " global.dat | awk '{s+=$34}END{printf "%.0f %.4f\n" ,9 , (s/3)}' >> estadisticaGlobal.dat


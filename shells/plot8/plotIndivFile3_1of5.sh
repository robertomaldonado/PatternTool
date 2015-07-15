#!/bin/sh

grep "default_3.txt" ../../files/default_3.txtplot_totales.txt > default_3plot.dat

grep "TNMQ " default_3plot.dat | awk '{s=$18}END{printf "%.0f %.4f\n" ,1 , s}' > estadisticaGlobalIndiv3.dat
grep "TNME " default_3plot.dat | awk '{s=$20}END{printf "%.0f %.4f\n" ,2 , s}' >> estadisticaGlobalIndiv3.dat
grep "TNE " default_3plot.dat | awk '{s=$22}END{printf "%.0f %.4f\n" ,3 , s}' >> estadisticaGlobalIndiv3.dat
grep "TNWAP " default_3plot.dat | awk '{s=$24}END{printf "%.0f %.4f\n" ,4 , s}' >> estadisticaGlobalIndiv3.dat
grep "TNK1 " default_3plot.dat | awk '{s=$26}END{printf "%.0f %.4f\n" ,5 , s}' >> estadisticaGlobalIndiv3.dat
grep "TNK2 " default_3plot.dat | awk '{s=$28}END{printf "%.0f %.4f\n" ,6 , s}' >> estadisticaGlobalIndiv3.dat
grep "TNK3 " default_3plot.dat | awk '{s=$30}END{printf "%.0f %.4f\n" ,7 , s}' >> estadisticaGlobalIndiv3.dat
grep "TNCBS " default_3plot.dat | awk '{s=$32}END{printf "%.0f %.4f\n" ,8 , s}' >> estadisticaGlobalIndiv3.dat
grep "TNCAS " default_3plot.dat | awk '{s=$34}END{printf "%.0f %.4f\n" ,9 , s}' >> estadisticaGlobalIndiv3.dat
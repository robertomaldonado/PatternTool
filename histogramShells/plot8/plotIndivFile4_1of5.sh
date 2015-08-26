#!/bin/sh

grep "default_4.txt" ../../files/default_4.txtplot_totales.txt > default_4plot.dat

grep "TNMQ " default_4plot.dat | awk '{s=$18}END{printf "%.0f %.4f\n" ,1 , s}' > estadisticaGlobalIndiv4.dat
grep "TNME " default_4plot.dat | awk '{s=$20}END{printf "%.0f %.4f\n" ,2 , s}' >> estadisticaGlobalIndiv4.dat
grep "TNE " default_4plot.dat | awk '{s=$22}END{printf "%.0f %.4f\n" ,3 , s}' >> estadisticaGlobalIndiv4.dat
grep "TNWAP " default_4plot.dat | awk '{s=$24}END{printf "%.0f %.4f\n" ,4 , s}' >> estadisticaGlobalIndiv4.dat
grep "TNK1 " default_4plot.dat | awk '{s=$26}END{printf "%.0f %.4f\n" ,5 , s}' >> estadisticaGlobalIndiv4.dat
grep "TNK2 " default_4plot.dat | awk '{s=$28}END{printf "%.0f %.4f\n" ,6 , s}' >> estadisticaGlobalIndiv4.dat
grep "TNK3 " default_4plot.dat | awk '{s=$30}END{printf "%.0f %.4f\n" ,7 , s}' >> estadisticaGlobalIndiv4.dat
grep "TNCBS " default_4plot.dat | awk '{s=$32}END{printf "%.0f %.4f\n" ,8 , s}' >> estadisticaGlobalIndiv4.dat
grep "TNCAS " default_4plot.dat | awk '{s=$34}END{printf "%.0f %.4f\n" ,9 , s}' >> estadisticaGlobalIndiv4.dat
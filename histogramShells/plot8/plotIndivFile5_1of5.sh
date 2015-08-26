#!/bin/sh

grep "default_5.txt" ../../files/default_5.txtplot_totales.txt > default_5plot.dat

grep "TNMQ " default_5plot.dat | awk '{s=$18}END{printf "%.0f %.4f\n" ,1 , s}' > estadisticaGlobalIndiv5.dat
grep "TNME " default_5plot.dat | awk '{s=$20}END{printf "%.0f %.4f\n" ,2 , s}' >> estadisticaGlobalIndiv5.dat
grep "TNE " default_5plot.dat | awk '{s=$22}END{printf "%.0f %.4f\n" ,3 , s}' >> estadisticaGlobalIndiv5.dat
grep "TNWAP " default_5plot.dat | awk '{s=$24}END{printf "%.0f %.4f\n" ,4 , s}' >> estadisticaGlobalIndiv5.dat
grep "TNK1 " default_5plot.dat | awk '{s=$26}END{printf "%.0f %.4f\n" ,5 , s}' >> estadisticaGlobalIndiv5.dat
grep "TNK2 " default_5plot.dat | awk '{s=$28}END{printf "%.0f %.4f\n" ,6 , s}' >> estadisticaGlobalIndiv5.dat
grep "TNK3 " default_5plot.dat | awk '{s=$30}END{printf "%.0f %.4f\n" ,7 , s}' >> estadisticaGlobalIndiv5.dat
grep "TNCBS " default_5plot.dat | awk '{s=$32}END{printf "%.0f %.4f\n" ,8 , s}' >> estadisticaGlobalIndiv5.dat
grep "TNCAS " default_5plot.dat | awk '{s=$34}END{printf "%.0f %.4f\n" ,9 , s}' >> estadisticaGlobalIndiv5.dat
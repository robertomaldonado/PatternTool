#!/bin/sh

grep "default_1.txt" ../../files/default_1.txtplot.txt > default_1plot.dat

grep "MPS " default_1plot.dat | awk '{s=$20}END{printf "%.0f %.0f\n" ,1 , s}' > estadisticaGlobalIndiv1.dat
grep "MMS " default_1plot.dat | awk '{s=$22}END{printf "%.0f %.0f\n" ,2 , s}' >> estadisticaGlobalIndiv1.dat
grep "MTS " default_1plot.dat | awk '{s=$24}END{printf "%.0f %.0f\n" ,3 , s}' >> estadisticaGlobalIndiv1.dat
grep "MMO " default_1plot.dat | awk '{s=$26}END{printf "%.0f %.0f\n" ,4 , s}' >> estadisticaGlobalIndiv1.dat

grep "MEQ " default_1plot.dat | awk '{s=$28}END{printf "%.0f %.0f\n" ,5 , s}' >> estadisticaGlobalIndiv1.dat
grep "MGR " default_1plot.dat | awk '{s=$30}END{printf "%.0f %.0f\n" ,6 , s}' >> estadisticaGlobalIndiv1.dat
grep "MLR " default_1plot.dat | awk '{s=$32}END{printf "%.0f %.0f\n" ,7 , s}' >> estadisticaGlobalIndiv1.dat
grep "MDN " default_1plot.dat | awk '{s=$34}END{printf "%.0f %.0f\n" ,8 , s}' >> estadisticaGlobalIndiv1.dat
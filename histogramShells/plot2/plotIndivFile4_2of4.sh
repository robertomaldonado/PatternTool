#!/bin/sh

grep "default_4.txt" ../../files/default_4.txtplot.txt > default_4.plot.dat

grep "MPS " default_4.plot.dat | awk '{s=$20}END{printf "%.0f %.0f\n" ,1 , s}' > estadisticaGlobalIndiv4.dat
grep "MMS " default_4.plot.dat | awk '{s=$22}END{printf "%.0f %.0f\n" ,2 , s}' >> estadisticaGlobalIndiv4.dat
grep "MTS " default_4.plot.dat | awk '{s=$24}END{printf "%.0f %.0f\n" ,3 , s}' >> estadisticaGlobalIndiv4.dat
grep "MMO " default_4.plot.dat | awk '{s=$26}END{printf "%.0f %.0f\n" ,4 , s}' >> estadisticaGlobalIndiv4.dat

grep "MEQ " default_4.plot.dat | awk '{s=$28}END{printf "%.0f %.0f\n" ,5 , s}' >> estadisticaGlobalIndiv4.dat
grep "MGR " default_4.plot.dat | awk '{s=$30}END{printf "%.0f %.0f\n" ,6 , s}' >> estadisticaGlobalIndiv4.dat
grep "MLR " default_4.plot.dat | awk '{s=$32}END{printf "%.0f %.0f\n" ,7 , s}' >> estadisticaGlobalIndiv4.dat
grep "MDN " default_4.plot.dat | awk '{s=$34}END{printf "%.0f %.0f\n" ,8 , s}' >> estadisticaGlobalIndiv4.dat

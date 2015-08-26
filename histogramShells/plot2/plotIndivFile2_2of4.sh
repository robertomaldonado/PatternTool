#!/bin/sh

grep "default_2.txt" ../../files/default_2.txtplot.txt > default_2.plot.dat

grep "MPS " default_2.plot.dat | awk '{s=$20}END{printf "%.0f %.0f\n" ,1 , s}' > estadisticaGlobalIndiv2.dat
grep "MMS " default_2.plot.dat | awk '{s=$22}END{printf "%.0f %.0f\n" ,2 , s}' >> estadisticaGlobalIndiv2.dat
grep "MTS " default_2.plot.dat | awk '{s=$24}END{printf "%.0f %.0f\n" ,3 , s}' >> estadisticaGlobalIndiv2.dat
grep "MMO " default_2.plot.dat | awk '{s=$26}END{printf "%.0f %.0f\n" ,4 , s}' >> estadisticaGlobalIndiv2.dat

grep "MEQ " default_2.plot.dat | awk '{s=$28}END{printf "%.0f %.0f\n" ,5 , s}' >> estadisticaGlobalIndiv2.dat
grep "MGR " default_2.plot.dat | awk '{s=$30}END{printf "%.0f %.0f\n" ,6 , s}' >> estadisticaGlobalIndiv2.dat
grep "MLR " default_2.plot.dat | awk '{s=$32}END{printf "%.0f %.0f\n" ,7 , s}' >> estadisticaGlobalIndiv2.dat
grep "MDN " default_2.plot.dat | awk '{s=$34}END{printf "%.0f %.0f\n" ,8 , s}' >> estadisticaGlobalIndiv2.dat
#!/bin/sh

grep "default_3.txt" ../../files/default_3.txtplot.txt > default_3.plot.dat

grep "MPS " default_3.plot.dat | awk '{s=$20}END{printf "%.0f %.0f\n" ,1 , s}' > estadisticaGlobalIndiv3.dat
grep "MMS " default_3.plot.dat | awk '{s=$22}END{printf "%.0f %.0f\n" ,2 , s}' >> estadisticaGlobalIndiv3.dat
grep "MTS " default_3.plot.dat | awk '{s=$24}END{printf "%.0f %.0f\n" ,3 , s}' >> estadisticaGlobalIndiv3.dat
grep "MMO " default_3.plot.dat | awk '{s=$26}END{printf "%.0f %.0f\n" ,4 , s}' >> estadisticaGlobalIndiv3.dat

grep "MEQ " default_3.plot.dat | awk '{s=$28}END{printf "%.0f %.0f\n" ,5 , s}' >> estadisticaGlobalIndiv3.dat
grep "MGR " default_3.plot.dat | awk '{s=$30}END{printf "%.0f %.0f\n" ,6 , s}' >> estadisticaGlobalIndiv3.dat
grep "MLR " default_3.plot.dat | awk '{s=$32}END{printf "%.0f %.0f\n" ,7 , s}' >> estadisticaGlobalIndiv3.dat
grep "MDN " default_3.plot.dat | awk '{s=$34}END{printf "%.0f %.0f\n" ,8 , s}' >> estadisticaGlobalIndiv3.dat

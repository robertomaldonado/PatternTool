#!/bin/sh

grep "default_3.txt" ../../files/default_3.txtplot.txt > default_3.plot.dat

grep "GPO " default_3.plot.dat | awk '{s=$36}END{printf "%.0f %.0f\n" ,1 , s}' > estadisticaGlobalIndiv3.dat
grep "GPC " default_3.plot.dat | awk '{s=$38}END{printf "%.0f %.0f\n" ,2 , s}' >> estadisticaGlobalIndiv3.dat
grep "GCO " default_3.plot.dat | awk '{s=$40}END{printf "%.0f %.0f\n" ,3 , s}' >> estadisticaGlobalIndiv3.dat
grep "GCC " default_3.plot.dat | awk '{s=$42}END{printf "%.0f %.0f\n" ,4 , s}' >> estadisticaGlobalIndiv3.dat

grep "GBO " default_3.plot.dat | awk '{s=$44}END{printf "%.0f %.0f\n" ,5 , s}' >> estadisticaGlobalIndiv3.dat
grep "GBC " default_3.plot.dat | awk '{s=$46}END{printf "%.0f %.0f\n" ,6 , s}' >> estadisticaGlobalIndiv3.dat

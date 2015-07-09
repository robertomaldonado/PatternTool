#!/bin/sh

grep "default_4.txt" ../../files/default_4.txtplot.txt > default_4.plot.dat

grep "GPO " default_4.plot.dat | awk '{s=$36}END{printf "%.0f %.0f\n" ,1 , s}' > estadisticaGlobalIndiv4.dat
grep "GPC " default_4.plot.dat | awk '{s=$38}END{printf "%.0f %.0f\n" ,2 , s}' >> estadisticaGlobalIndiv4.dat
grep "GCO " default_4.plot.dat | awk '{s=$40}END{printf "%.0f %.0f\n" ,3 , s}' >> estadisticaGlobalIndiv4.dat
grep "GCC " default_4.plot.dat | awk '{s=$42}END{printf "%.0f %.0f\n" ,4 , s}' >> estadisticaGlobalIndiv4.dat

grep "GBO " default_4.plot.dat | awk '{s=$44}END{printf "%.0f %.0f\n" ,5 , s}' >> estadisticaGlobalIndiv4.dat
grep "GBC " default_4.plot.dat | awk '{s=$46}END{printf "%.0f %.0f\n" ,6 , s}' >> estadisticaGlobalIndiv4.dat

#!/bin/sh

grep "default_5.txt" ../../files/default_5.txtplot.txt > default_5.plot.dat

grep "GPO " default_5.plot.dat | awk '{s=$36}END{printf "%.0f %.0f\n" ,1 , s}' > estadisticaGlobalIndiv5.dat
grep "GPC " default_5.plot.dat | awk '{s=$38}END{printf "%.0f %.0f\n" ,2 , s}' >> estadisticaGlobalIndiv5.dat
grep "GCO " default_5.plot.dat | awk '{s=$40}END{printf "%.0f %.0f\n" ,3 , s}' >> estadisticaGlobalIndiv5.dat
grep "GCC " default_5.plot.dat | awk '{s=$42}END{printf "%.0f %.0f\n" ,4 , s}' >> estadisticaGlobalIndiv5.dat

grep "GBO " default_5.plot.dat | awk '{s=$44}END{printf "%.0f %.0f\n" ,5 , s}' >> estadisticaGlobalIndiv5.dat
grep "GBC " default_5.plot.dat | awk '{s=$46}END{printf "%.0f %.0f\n" ,6 , s}' >> estadisticaGlobalIndiv5.dat

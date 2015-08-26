#!/bin/sh

grep "default_2.txt" ../../files/default_2.txtplot.txt > default_2.plot.dat

grep "GPO " default_2.plot.dat | awk '{s=$36}END{printf "%.0f %.0f\n" ,1 , s}' > estadisticaGlobalIndiv2.dat
grep "GPC " default_2.plot.dat | awk '{s=$38}END{printf "%.0f %.0f\n" ,2 , s}' >> estadisticaGlobalIndiv2.dat
grep "GCO " default_2.plot.dat | awk '{s=$40}END{printf "%.0f %.0f\n" ,3 , s}' >> estadisticaGlobalIndiv2.dat
grep "GCC " default_2.plot.dat | awk '{s=$42}END{printf "%.0f %.0f\n" ,4 , s}' >> estadisticaGlobalIndiv2.dat

grep "GBO " default_2.plot.dat | awk '{s=$44}END{printf "%.0f %.0f\n" ,5 , s}' >> estadisticaGlobalIndiv2.dat
grep "GBC " default_2.plot.dat | awk '{s=$46}END{printf "%.0f %.0f\n" ,6 , s}' >> estadisticaGlobalIndiv2.dat
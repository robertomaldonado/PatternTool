#!/bin/sh

grep "default_3.txt" ../../files/default_3.txtplot.txt > default_3.plot.dat

grep "OBS " default_3.plot.dat | awk '{s=$48}END{printf "%.0f %.0f\n" ,1 , s}' > estadisticaGlobalIndiv3.dat
grep "OAA " default_3.plot.dat | awk '{s=$50}END{printf "%.0f %.0f\n" ,2 , s}' >> estadisticaGlobalIndiv3.dat
grep "ONS " default_3.plot.dat | awk '{s=$52}END{printf "%.0f %.0f\n" ,3 , s}' >> estadisticaGlobalIndiv3.dat
grep "ODS " default_3.plot.dat | awk '{s=$54}END{printf "%.0f %.0f\n" ,4 , s}' >> estadisticaGlobalIndiv3.dat

grep "OHO " default_3.plot.dat | awk '{s=$56}END{printf "%.0f %.0f\n" ,5 , s}' >> estadisticaGlobalIndiv3.dat
grep "ONP " default_3.plot.dat | awk '{s=$58}END{printf "%.0f %.0f\n" ,6 , s}' >> estadisticaGlobalIndiv3.dat
grep "OVD " default_3.plot.dat | awk '{s=$60}END{printf "%.0f %.0f\n" ,7 , s}' >> estadisticaGlobalIndiv3.dat
grep "OPS " default_3.plot.dat | awk '{s=$62}END{printf "%.0f %.0f\n" ,8 , s}' >> estadisticaGlobalIndiv3.dat
grep "OUS " default_3.plot.dat | awk '{s=$64}END{printf "%.0f %.0f\n" ,9 , s}' >> estadisticaGlobalIndiv3.dat

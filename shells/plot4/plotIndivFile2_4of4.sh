#!/bin/sh

grep "default_2.txt" ../../files/default_2.txtplot.txt > default_2.plot.dat

grep "OBS " default_2.plot.dat | awk '{s=$48}END{printf "%.0f %.0f\n" ,1 , s}' > estadisticaGlobalIndiv2.dat
grep "OAA " default_2.plot.dat | awk '{s=$50}END{printf "%.0f %.0f\n" ,2 , s}' >> estadisticaGlobalIndiv2.dat
grep "ONS " default_2.plot.dat | awk '{s=$52}END{printf "%.0f %.0f\n" ,3 , s}' >> estadisticaGlobalIndiv2.dat
grep "ODS " default_2.plot.dat | awk '{s=$54}END{printf "%.0f %.0f\n" ,4 , s}' >> estadisticaGlobalIndiv2.dat

grep "OHO " default_2.plot.dat | awk '{s=$56}END{printf "%.0f %.0f\n" ,5 , s}' >> estadisticaGlobalIndiv2.dat
grep "ONP " default_2.plot.dat | awk '{s=$58}END{printf "%.0f %.0f\n" ,6 , s}' >> estadisticaGlobalIndiv2.dat
grep "OVD " default_2.plot.dat | awk '{s=$60}END{printf "%.0f %.0f\n" ,7 , s}' >> estadisticaGlobalIndiv2.dat
grep "OPS " default_2.plot.dat | awk '{s=$62}END{printf "%.0f %.0f\n" ,8 , s}' >> estadisticaGlobalIndiv2.dat
grep "OUS " default_2.plot.dat | awk '{s=$64}END{printf "%.0f %.0f\n" ,9 , s}' >> estadisticaGlobalIndiv2.dat
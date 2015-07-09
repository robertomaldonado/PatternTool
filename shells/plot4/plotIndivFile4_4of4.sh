#!/bin/sh

grep "default_4.txt" ../../files/default_4.txtplot.txt > default_4.plot.dat

grep "OBS " default_4.plot.dat | awk '{s=$48}END{printf "%.0f %.0f\n" ,1 , s}' > estadisticaGlobalIndiv4.dat
grep "OAA " default_4.plot.dat | awk '{s=$50}END{printf "%.0f %.0f\n" ,2 , s}' >> estadisticaGlobalIndiv4.dat
grep "ONS " default_4.plot.dat | awk '{s=$52}END{printf "%.0f %.0f\n" ,3 , s}' >> estadisticaGlobalIndiv4.dat
grep "ODS " default_4.plot.dat | awk '{s=$54}END{printf "%.0f %.0f\n" ,4 , s}' >> estadisticaGlobalIndiv4.dat

grep "OHO " default_4.plot.dat | awk '{s=$56}END{printf "%.0f %.0f\n" ,5 , s}' >> estadisticaGlobalIndiv4.dat
grep "ONP " default_4.plot.dat | awk '{s=$58}END{printf "%.0f %.0f\n" ,6 , s}' >> estadisticaGlobalIndiv4.dat
grep "OVD " default_4.plot.dat | awk '{s=$60}END{printf "%.0f %.0f\n" ,7 , s}' >> estadisticaGlobalIndiv4.dat

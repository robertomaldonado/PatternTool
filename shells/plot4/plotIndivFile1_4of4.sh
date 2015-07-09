#!/bin/sh

grep "default_1.txt" ../../files/default_1.txtplot.txt > default_1plot.dat

grep "OBS " default_1plot.dat | awk '{s=$48}END{printf "%.0f %.0f\n" ,1 , s}' > estadisticaGlobalIndiv1.dat
grep "OAA " default_1plot.dat | awk '{s=$50}END{printf "%.0f %.0f\n" ,2 , s}' >> estadisticaGlobalIndiv1.dat
grep "ONS " default_1plot.dat | awk '{s=$52}END{printf "%.0f %.0f\n" ,3 , s}' >> estadisticaGlobalIndiv1.dat
grep "ODS " default_1plot.dat | awk '{s=$54}END{printf "%.0f %.0f\n" ,4 , s}' >> estadisticaGlobalIndiv1.dat

grep "OHO " default_1plot.dat | awk '{s=$56}END{printf "%.0f %.0f\n" ,5 , s}' >> estadisticaGlobalIndiv1.dat
grep "ONP " default_1plot.dat | awk '{s=$58}END{printf "%.0f %.0f\n" ,6 , s}' >> estadisticaGlobalIndiv1.dat
grep "OVP " default_1plot.dat | awk '{s=$60}END{printf "%.0f %.0f\n" ,7 , s}' >> estadisticaGlobalIndiv1.dat
grep "OPS " default_1plot.dat | awk '{s=$62}END{printf "%.0f %.0f\n" ,8 , s}' >> estadisticaGlobalIndiv1.dat
grep "OUS " default_1plot.dat | awk '{s=$64}END{printf "%.0f %.0f\n" ,9 , s}' >> estadisticaGlobalIndiv1.dat

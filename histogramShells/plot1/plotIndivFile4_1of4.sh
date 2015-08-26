#!/bin/sh

grep "default_4.txt" ../../files/default_4.txtplot.txt > default_4.plot.dat

grep "PPD " default_4.plot.dat | awk '{s=$4}END{printf "%.0f %.4f\n" ,1 , s}' > estadisticaGlobalIndiv4.dat
grep "PCN " default_4.plot.dat | awk '{s=$6}END{printf "%.0f %.4f\n" ,2 , s}' >> estadisticaGlobalIndiv4.dat
grep "PCA " default_4.plot.dat | awk '{s=$8}END{printf "%.0f %.4f\n" ,3 , s}' >> estadisticaGlobalIndiv4.dat
grep "PSC " default_4.plot.dat | awk '{s=$10}END{printf "%.0f %.4f\n" ,4 , s}' >> estadisticaGlobalIndiv4.dat

grep "EEO " default_4.plot.dat | awk '{s=$12}END{printf "%.0f %.4f\n" ,5 , s}' >> estadisticaGlobalIndiv4.dat
grep "EEC " default_4.plot.dat | awk '{s=$14}END{printf "%.0f %.4f\n" ,6 , s}' >> estadisticaGlobalIndiv4.dat
grep "EQO " default_4.plot.dat | awk '{s=$16}END{printf "%.0f %.4f\n" ,7 , s}' >> estadisticaGlobalIndiv4.dat
grep "EQC " default_4.plot.dat | awk '{s=$18}END{printf "%.0f %.4f\n" ,8 , s}' >> estadisticaGlobalIndiv4.dat

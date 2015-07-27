#!/bin/sh

grep "default_2.txt" ../../files/default_2.txtplot.txt > default_2.plot.dat

grep "PPD " default_2.plot.dat | awk '{s=$4}END{printf "%.4f %.4f\n" , s, 0}' > estadisticaGlobalIndiv2.dat
grep "PCN " default_2.plot.dat | awk '{s=$6}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv2.dat
grep "PCA " default_2.plot.dat | awk '{s=$8}END{printf "%.4f %.4f\n", s, 0}' >> estadisticaGlobalIndiv2.dat
grep "PSC " default_2.plot.dat | awk '{s=$10}END{printf "%.4f %.4f\n", s, 0}' >> estadisticaGlobalIndiv2.dat

grep "EEO " default_2.plot.dat | awk '{s=$12}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv2.dat
grep "EEC " default_2.plot.dat | awk '{s=$14}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv2.dat
grep "EQO " default_2.plot.dat | awk '{s=$16}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv2.dat
grep "EQC " default_2.plot.dat | awk '{s=$18}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv2.dat
#!/bin/sh

grep "default_3.txt" ../../files/default_3.txtplot.txt > default_3.plot.dat

grep "PPD " default_3.plot.dat | awk '{s=$4}END{printf "%.4f %.4f\n" , s, 0}' > estadisticaGlobalIndiv3.dat
grep "PCN " default_3.plot.dat | awk '{s=$6}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv3.dat
grep "PCA " default_3.plot.dat | awk '{s=$8}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv3.dat
grep "PSC " default_3.plot.dat | awk '{s=$10}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv3.dat
grep "EEO " default_3.plot.dat | awk '{s=$12}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv3.dat
grep "EEC " default_3.plot.dat | awk '{s=$14}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv3.dat
grep "EQO " default_3.plot.dat | awk '{s=$16}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv3.dat
grep "EQC " default_3.plot.dat | awk '{s=$18}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv3.dat
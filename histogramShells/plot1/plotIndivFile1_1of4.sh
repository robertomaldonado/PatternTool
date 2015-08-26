#!/bin/sh

grep "default_1.txt" ../../files/default_1.txtplot.txt > default_1plot.dat

grep "PPD " default_1plot.dat | awk '{s=$4}END{printf "%.0f %.4f\n" ,1 , s}' > estadisticaGlobalIndiv1.dat
grep "PCN " default_1plot.dat | awk '{s=$6}END{printf "%.0f %.4f\n" ,2 , s}' >> estadisticaGlobalIndiv1.dat
grep "PCA " default_1plot.dat | awk '{s=$8}END{printf "%.0f %.4f\n" ,3 , s}' >> estadisticaGlobalIndiv1.dat
grep "PSC " default_1plot.dat | awk '{s=$10}END{printf "%.0f %.4f\n" ,4 , s}' >> estadisticaGlobalIndiv1.dat

grep "EEO " default_1plot.dat | awk '{s=$12}END{printf "%.0f %.4f\n" ,5 , s}' >> estadisticaGlobalIndiv1.dat
grep "EEC " default_1plot.dat | awk '{s=$14}END{printf "%.0f %.4f\n" ,6 , s}' >> estadisticaGlobalIndiv1.dat
grep "EQO " default_1plot.dat | awk '{s=$16}END{printf "%.0f %.4f\n" ,7 , s}' >> estadisticaGlobalIndiv1.dat
grep "EQC " default_1plot.dat | awk '{s=$18}END{printf "%.0f %.4f\n" ,8 , s}' >> estadisticaGlobalIndiv1.dat
#!/bin/sh

grep "default_6.txt" ../../files/default_6.txtplot_averages.txt > default_6plot.dat

grep "AWL " default_6plot.dat | awk '{s=$4}END{printf "%.0f %.4f\n" ,1 , s}' > estadisticaGlobalIndiv6.dat
grep "AWPS " default_6plot.dat | awk '{s=$6}END{printf "%.0f %.4f\n" ,2 , s}' >> estadisticaGlobalIndiv6.dat
grep "AWPP " default_6plot.dat | awk '{s=$8}END{printf "%.0f %.4f\n" ,3 , s}' >> estadisticaGlobalIndiv6.dat
grep "ADPP " default_6plot.dat | awk '{s=$10}END{printf "%.0f %.4f\n" ,4 , s}' >> estadisticaGlobalIndiv6.dat
grep "ACPP " default_6plot.dat | awk '{s=$12}END{printf "%.0f %.4f\n" ,5 , s}' >> estadisticaGlobalIndiv6.dat

grep "ACOPP " default_6plot.dat | awk '{s=$14}END{printf "%.0f %.4f\n" ,6 , s}' >> estadisticaGlobalIndiv6.dat
grep "ASCPP " default_6plot.dat | awk '{s=$16}END{printf "%.0f %.4f\n" ,7 , s}' >> estadisticaGlobalIndiv6.dat
grep "AQPP " default_6plot.dat | awk '{s=$18}END{printf "%.0f %.4f\n" ,8 , s}' >> estadisticaGlobalIndiv6.dat
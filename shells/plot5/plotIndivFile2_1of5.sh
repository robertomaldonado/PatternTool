#!/bin/sh

grep "default_2.txt" ../../files/default_2.txtplot_averages.txt > default_2plot.dat

grep "AWL " default_2plot.dat | awk '{s=$4}END{printf "%.0f %.4f\n" ,1 , s}' > estadisticaGlobalIndiv2.dat
grep "AWPS " default_2plot.dat | awk '{s=$6}END{printf "%.0f %.4f\n" ,2 , s}' >> estadisticaGlobalIndiv2.dat
grep "AWPP " default_2plot.dat | awk '{s=$8}END{printf "%.0f %.4f\n" ,3 , s}' >> estadisticaGlobalIndiv2.dat
grep "ADPP " default_2plot.dat | awk '{s=$10}END{printf "%.0f %.4f\n" ,4 , s}' >> estadisticaGlobalIndiv2.dat
grep "ACPP " default_2plot.dat | awk '{s=$12}END{printf "%.0f %.4f\n" ,5 , s}' >> estadisticaGlobalIndiv2.dat

grep "ACOPP " default_2plot.dat | awk '{s=$14}END{printf "%.0f %.4f\n" ,6 , s}' >> estadisticaGlobalIndiv2.dat
grep "ASCPP " default_2plot.dat | awk '{s=$16}END{printf "%.0f %.4f\n" ,7 , s}' >> estadisticaGlobalIndiv2.dat
grep "AQPP " default_2plot.dat | awk '{s=$18}END{printf "%.0f %.4f\n" ,8 , s}' >> estadisticaGlobalIndiv2.dat
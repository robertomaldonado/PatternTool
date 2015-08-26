#!/bin/sh

grep "default_5.txt" ../../files/default_5.txtplot_averages.txt > default_5plot.dat

grep "AWL " default_5plot.dat | awk '{s=$4}END{printf "%.0f %.4f\n" ,1 , s}' > estadisticaGlobalIndiv5.dat
grep "AWPS " default_5plot.dat | awk '{s=$6}END{printf "%.0f %.4f\n" ,2 , s}' >> estadisticaGlobalIndiv5.dat
grep "AWPP " default_5plot.dat | awk '{s=$8}END{printf "%.0f %.4f\n" ,3 , s}' >> estadisticaGlobalIndiv5.dat
grep "ADPP " default_5plot.dat | awk '{s=$10}END{printf "%.0f %.4f\n" ,4 , s}' >> estadisticaGlobalIndiv5.dat
grep "ACPP " default_5plot.dat | awk '{s=$12}END{printf "%.0f %.4f\n" ,5 , s}' >> estadisticaGlobalIndiv5.dat

grep "ACOPP " default_5plot.dat | awk '{s=$14}END{printf "%.0f %.4f\n" ,6 , s}' >> estadisticaGlobalIndiv5.dat
grep "ASCPP " default_5plot.dat | awk '{s=$16}END{printf "%.0f %.4f\n" ,7 , s}' >> estadisticaGlobalIndiv5.dat
grep "AQPP " default_5plot.dat | awk '{s=$18}END{printf "%.0f %.4f\n" ,8 , s}' >> estadisticaGlobalIndiv5.dat
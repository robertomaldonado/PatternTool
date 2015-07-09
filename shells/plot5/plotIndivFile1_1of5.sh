#!/bin/sh

grep "default_1.txt" ../../files/default_1.txtplot_tildes.txt > default_1plot.dat

grep "MAA " default_1plot.dat | awk '{s=$4}END{printf "%.0f %.4f\n" ,1 , s}' > estadisticaGlobalIndiv1.dat
grep "MAE " default_1plot.dat | awk '{s=$6}END{printf "%.0f %.4f\n" ,2 , s}' >> estadisticaGlobalIndiv1.dat
grep "MAI " default_1plot.dat | awk '{s=$8}END{printf "%.0f %.4f\n" ,3 , s}' >> estadisticaGlobalIndiv1.dat
grep "MAO " default_1plot.dat | awk '{s=$10}END{printf "%.0f %.4f\n" ,4 , s}' >> estadisticaGlobalIndiv1.dat
grep "MAU " default_1plot.dat | awk '{s=$12}END{printf "%.0f %.4f\n" ,5 , s}' >> estadisticaGlobalIndiv1.dat

grep "MIA " default_1plot.dat | awk '{s=$14}END{printf "%.0f %.4f\n" ,6 , s}' >> estadisticaGlobalIndiv1.dat
grep "MIE " default_1plot.dat | awk '{s=$16}END{printf "%.0f %.4f\n" ,7 , s}' >> estadisticaGlobalIndiv1.dat
grep "MII " default_1plot.dat | awk '{s=$18}END{printf "%.0f %.4f\n" ,8 , s}' >> estadisticaGlobalIndiv1.dat
grep "MIO " default_1plot.dat | awk '{s=$16}END{printf "%.0f %.4f\n" ,9 , s}' >> estadisticaGlobalIndiv1.dat
grep "MIU " default_1plot.dat | awk '{s=$18}END{printf "%.0f %.4f\n" ,10 , s}' >> estadisticaGlobalIndiv1.dat
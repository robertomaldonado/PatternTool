#!/bin/sh

grep "default_2.txt" ../../files/default_2.txtplot_tildes.txt > default_2plot.dat

grep "MAA " default_2plot.dat | awk '{s=$4}END{printf "%.0f %.4f\n" ,1 , s}' > estadisticaGlobalIndiv2.dat
grep "MAE " default_2plot.dat | awk '{s=$6}END{printf "%.0f %.4f\n" ,2 , s}' >> estadisticaGlobalIndiv2.dat
grep "MAI " default_2plot.dat | awk '{s=$8}END{printf "%.0f %.4f\n" ,3 , s}' >> estadisticaGlobalIndiv2.dat
grep "MAO " default_2plot.dat | awk '{s=$10}END{printf "%.0f %.4f\n" ,4 , s}' >> estadisticaGlobalIndiv2.dat
grep "MAU " default_2plot.dat | awk '{s=$12}END{printf "%.0f %.4f\n" ,5 , s}' >> estadisticaGlobalIndiv2.dat

grep "MIA " default_2plot.dat | awk '{s=$14}END{printf "%.0f %.4f\n" ,6 , s}' >> estadisticaGlobalIndiv2.dat
grep "MIE " default_2plot.dat | awk '{s=$16}END{printf "%.0f %.4f\n" ,7 , s}' >> estadisticaGlobalIndiv2.dat
grep "MII " default_2plot.dat | awk '{s=$18}END{printf "%.0f %.4f\n" ,8 , s}' >> estadisticaGlobalIndiv2.dat
grep "MIO " default_2plot.dat | awk '{s=$16}END{printf "%.0f %.4f\n" ,9 , s}' >> estadisticaGlobalIndiv2.dat
grep "MIU " default_2plot.dat | awk '{s=$18}END{printf "%.0f %.4f\n" ,10 , s}' >> estadisticaGlobalIndiv2.dat
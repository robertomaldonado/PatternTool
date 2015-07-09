#!/bin/sh

grep "default_5.txt" ../../files/default_5.txtplot_tildes.txt > default_5plot.dat

grep "MAA " default_5plot.dat | awk '{s=$4}END{printf "%.0f %.4f\n" ,1 , s}' > estadisticaGlobalIndiv5.dat
grep "MAE " default_5plot.dat | awk '{s=$6}END{printf "%.0f %.4f\n" ,2 , s}' >> estadisticaGlobalIndiv5.dat
grep "MAI " default_5plot.dat | awk '{s=$8}END{printf "%.0f %.4f\n" ,3 , s}' >> estadisticaGlobalIndiv5.dat
grep "MAO " default_5plot.dat | awk '{s=$10}END{printf "%.0f %.4f\n" ,4 , s}' >> estadisticaGlobalIndiv5.dat
grep "MAU " default_5plot.dat | awk '{s=$12}END{printf "%.0f %.4f\n" ,5 , s}' >> estadisticaGlobalIndiv5.dat

grep "MIA " default_5plot.dat | awk '{s=$14}END{printf "%.0f %.4f\n" ,6 , s}' >> estadisticaGlobalIndiv5.dat
grep "MIE " default_5plot.dat | awk '{s=$16}END{printf "%.0f %.4f\n" ,7 , s}' >> estadisticaGlobalIndiv5.dat
grep "MII " default_5plot.dat | awk '{s=$18}END{printf "%.0f %.4f\n" ,8 , s}' >> estadisticaGlobalIndiv5.dat
grep "MIO " default_5plot.dat | awk '{s=$16}END{printf "%.0f %.4f\n" ,9 , s}' >> estadisticaGlobalIndiv5.dat
grep "MIU " default_5plot.dat | awk '{s=$18}END{printf "%.0f %.4f\n" ,10 , s}' >> estadisticaGlobalIndiv5.dat
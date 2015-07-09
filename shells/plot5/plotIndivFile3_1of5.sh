#!/bin/sh

grep "default_3.txt" ../../files/default_3.txtplot_tildes.txt > default_3plot.dat

grep "MAA " default_3plot.dat | awk '{s=$4}END{printf "%.0f %.4f\n" ,1 , s}' > estadisticaGlobalIndiv3.dat
grep "MAE " default_3plot.dat | awk '{s=$6}END{printf "%.0f %.4f\n" ,2 , s}' >> estadisticaGlobalIndiv3.dat
grep "MAI " default_3plot.dat | awk '{s=$8}END{printf "%.0f %.4f\n" ,3 , s}' >> estadisticaGlobalIndiv3.dat
grep "MAO " default_3plot.dat | awk '{s=$10}END{printf "%.0f %.4f\n" ,4 , s}' >> estadisticaGlobalIndiv3.dat
grep "MAU " default_3plot.dat | awk '{s=$12}END{printf "%.0f %.4f\n" ,5 , s}' >> estadisticaGlobalIndiv3.dat

grep "MIA " default_3plot.dat | awk '{s=$14}END{printf "%.0f %.4f\n" ,6 , s}' >> estadisticaGlobalIndiv3.dat
grep "MIE " default_3plot.dat | awk '{s=$16}END{printf "%.0f %.4f\n" ,7 , s}' >> estadisticaGlobalIndiv3.dat
grep "MII " default_3plot.dat | awk '{s=$18}END{printf "%.0f %.4f\n" ,8 , s}' >> estadisticaGlobalIndiv3.dat
grep "MIO " default_3plot.dat | awk '{s=$16}END{printf "%.0f %.4f\n" ,9 , s}' >> estadisticaGlobalIndiv3.dat
grep "MIU " default_3plot.dat | awk '{s=$18}END{printf "%.0f %.4f\n" ,10 , s}' >> estadisticaGlobalIndiv3.dat
#!/bin/sh

grep "default_6.txt" ../../files/default_6.txtplot_tildes.txt > default_6plot.dat

grep "MAA " default_6plot.dat | awk '{s=$4}END{printf "%.0f %.4f\n" ,1 , s}' > estadisticaGlobalIndiv6.dat
grep "MAE " default_6plot.dat | awk '{s=$6}END{printf "%.0f %.4f\n" ,2 , s}' >> estadisticaGlobalIndiv6.dat
grep "MAI " default_6plot.dat | awk '{s=$8}END{printf "%.0f %.4f\n" ,3 , s}' >> estadisticaGlobalIndiv6.dat
grep "MAO " default_6plot.dat | awk '{s=$10}END{printf "%.0f %.4f\n" ,4 , s}' >> estadisticaGlobalIndiv6.dat
grep "MAU " default_6plot.dat | awk '{s=$12}END{printf "%.0f %.4f\n" ,5 , s}' >> estadisticaGlobalIndiv6.dat

grep "MIA " default_6plot.dat | awk '{s=$14}END{printf "%.0f %.4f\n" ,6 , s}' >> estadisticaGlobalIndiv6.dat
grep "MIE " default_6plot.dat | awk '{s=$16}END{printf "%.0f %.4f\n" ,7 , s}' >> estadisticaGlobalIndiv6.dat
grep "MII " default_6plot.dat | awk '{s=$18}END{printf "%.0f %.4f\n" ,8 , s}' >> estadisticaGlobalIndiv6.dat
grep "MIO " default_6plot.dat | awk '{s=$16}END{printf "%.0f %.4f\n" ,9 , s}' >> estadisticaGlobalIndiv6.dat
grep "MIU " default_6plot.dat | awk '{s=$18}END{printf "%.0f %.4f\n" ,10 , s}' >> estadisticaGlobalIndiv6.dat
#!/bin/sh

grep "default_4.txt" ../../files/default_4.txtplot_totales.txt > default_4plot.dat

grep "TUS " default_4plot.dat | awk '{s=$4}END{printf "%.0f %.4f\n" ,1 , s}' > estadisticaGlobalIndiv4.dat
grep "TLS " default_4plot.dat | awk '{s=$6}END{printf "%.0f %.4f\n" ,2 , s}' >> estadisticaGlobalIndiv4.dat
grep "TNW " default_4plot.dat | awk '{s=$8}END{printf "%.0f %.4f\n" ,3 , s}' >> estadisticaGlobalIndiv4.dat
grep "TNS " default_4plot.dat | awk '{s=$10}END{printf "%.0f %.4f\n" ,4 , s}' >> estadisticaGlobalIndiv4.dat
grep "TNP " default_4plot.dat | awk '{s=$12}END{printf "%.0f %.4f\n" ,5 , s}' >> estadisticaGlobalIndiv4.dat
grep "TNT " default_4plot.dat | awk '{s=$14}END{printf "%.0f %.4f\n" ,6 , s}' >> estadisticaGlobalIndiv4.dat

grep "TNWS " default_4plot.dat | awk '{s=$16}END{printf "%.0f %.4f\n" ,7 , s}' >> estadisticaGlobalIndiv4.dat
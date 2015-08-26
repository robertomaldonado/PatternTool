#!/bin/sh

grep "default_2.txt" ../../files/default_2.txtplot_averages.txt > default_2plot.dat

grep "AMQPP " default_2plot.dat | awk '{s=$20}END{printf "%.0f %.4f\n" ,1 , s}' > estadisticaGlobalIndiv2.dat
grep "AWSPS " default_2plot.dat | awk '{s=$22}END{printf "%.0f %.4f\n" ,2 , s}' >> estadisticaGlobalIndiv2.dat
grep "AK1 " default_2plot.dat | awk '{s=$24}END{printf "%.0f %.4f\n" ,3 , s}' >> estadisticaGlobalIndiv2.dat
grep "AK2 " default_2plot.dat | awk '{s=$26}END{printf "%.0f %.4f\n" ,4 , s}' >> estadisticaGlobalIndiv2.dat
grep "AK3 " default_2plot.dat | awk '{s=$28}END{printf "%.0f %.4f\n" ,5 , s}' >> estadisticaGlobalIndiv2.dat
grep "AWS " default_2plot.dat | awk '{s=$30}END{printf "%.0f %.4f\n" ,6 , s}' >> estadisticaGlobalIndiv2.dat

grep "ACAS " default_2plot.dat | awk '{s=$32}END{printf "%.0f %.4f\n" ,7 , s}' >> estadisticaGlobalIndiv2.dat
grep "ACBS " default_2plot.dat | awk '{s=$34}END{printf "%.0f %.4f\n" ,8 , s}' >> estadisticaGlobalIndiv2.dat
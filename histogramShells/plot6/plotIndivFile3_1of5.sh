#!/bin/sh

grep "default_3.txt" ../../files/default_3.txtplot_averages.txt > default_3plot.dat

grep "AMQPP " default_3plot.dat | awk '{s=$20}END{printf "%.0f %.4f\n" ,1 , s}' > estadisticaGlobalIndiv3.dat
grep "AWSPS " default_3plot.dat | awk '{s=$22}END{printf "%.0f %.4f\n" ,2 , s}' >> estadisticaGlobalIndiv3.dat
grep "AK1 " default_3plot.dat | awk '{s=$24}END{printf "%.0f %.4f\n" ,3 , s}' >> estadisticaGlobalIndiv3.dat
grep "AK2 " default_3plot.dat | awk '{s=$26}END{printf "%.0f %.4f\n" ,4 , s}' >> estadisticaGlobalIndiv3.dat
grep "AK3 " default_3plot.dat | awk '{s=$28}END{printf "%.0f %.4f\n" ,5 , s}' >> estadisticaGlobalIndiv3.dat
grep "AWS " default_3plot.dat | awk '{s=$30}END{printf "%.0f %.4f\n" ,6 , s}' >> estadisticaGlobalIndiv3.dat

grep "ACAS " default_3plot.dat | awk '{s=$32}END{printf "%.0f %.4f\n" ,7 , s}' >> estadisticaGlobalIndiv3.dat
grep "ACBS " default_3plot.dat | awk '{s=$34}END{printf "%.0f %.4f\n" ,8 , s}' >> estadisticaGlobalIndiv3.dat
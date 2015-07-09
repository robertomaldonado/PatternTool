#!/bin/sh

rm *.dat
echo "Archivos eliminados"

./plotAvg1of4.sh
./plotIndivFile1_1of4.sh
./plotIndivFile2_1of4.sh
./plotIndivFile3_1of4.sh
./plotIndivFile4_1of4.sh
./plotIndivFile5_1of4.sh
./plotIndivFile6_1of4.sh

echo "Graficacion de resultados"
./GraphGen1.sh

#rm *.dat
#echo "Limpieza de directorio"
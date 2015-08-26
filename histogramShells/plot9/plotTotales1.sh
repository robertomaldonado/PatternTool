#!/bin/sh

rm *.dat
echo "Archivos eliminados"

./plotAvg1of5.sh
./plotIndivFile1_1of5.sh
./plotIndivFile2_1of5.sh
./plotIndivFile3_1of5.sh
./plotIndivFile4_1of5.sh
./plotIndivFile5_1of5.sh
./plotIndivFile6_1of5.sh

echo "Graficacion de resultados"
./GraphGen7.sh

#rm *.dat
#echo "Limpieza de directorio"
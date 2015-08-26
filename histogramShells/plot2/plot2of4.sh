#!/bin/sh

rm *.dat
echo "Archivos eliminados"

./plotAvg2of4.sh
./plotIndivFile1_2of4.sh
./plotIndivFile2_2of4.sh
./plotIndivFile3_2of4.sh
./plotIndivFile4_2of4.sh
./plotIndivFile5_2of4.sh

echo "Graficacion de resultados"
./GraphGen2.sh


#rm *.dat
#echo "Limpieza de directorio"
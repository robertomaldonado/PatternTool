#!/bin/sh

rm *.dat
echo "Archivos eliminados"

./plotAvg3of4.sh
./plotIndivFile1_3of4.sh
./plotIndivFile2_3of4.sh
./plotIndivFile3_3of4.sh
./plotIndivFile4_3of4.sh
./plotIndivFile5_3of4.sh

echo "Graficacion de resultados"
./GraphGen3.sh


#rm *.dat
#echo "Limpieza de directorio"
#!/bin/sh

rm *.dat
echo "Archivos eliminados"

./plotAvg4of4.sh
./plotIndivFile1_4of4.sh
./plotIndivFile2_4of4.sh
./plotIndivFile3_4of4.sh
./plotIndivFile4_4of4.sh
./plotIndivFile5_4of4.sh


echo "Graficacion de resultados"
./GraphGen4.sh


#rm *.dat
#echo "Limpieza de directorio"
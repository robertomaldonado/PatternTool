#!/bin/sh

echo "Incio del 1er plot"
cd plot1
./plot1of4.sh
echo "Directorio 1"
cd ..
echo "Fin del 1er plot"

echo "Incio del 2do plot"
cd plot2
./plot2of4.sh
echo "Directorio 2"
cd ..
echo "Fin del 2do plot"

echo "Incio del 3er plot"
cd plot3
./plot3of4.sh
echo "Directorio 3"
cd ..
echo "Fin del 3er plot"

echo "Incio del 4to plot"
cd plot4
./plot4of4.sh
echo "Directorio 4"
cd ..
echo "Fin del 4to plot"

echo "Incio de plot Tildes"
cd plot5
./plotTildes.sh
echo "Directorio 5"
cd ..
echo "Fin del 5to plot"



#rm *.dat
#echo "Archivos .dat eliminados"
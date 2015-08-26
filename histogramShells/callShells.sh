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

echo "Incio de plot Promedios"
cd plot5
./plotAverages1.sh
echo "Directorio 5"
cd ..
echo "Fin del 5to plot"

echo "Continuacion de plot Promedios"
cd plot6
./plotAverages2.sh
echo "Directorio 6"
cd ..
echo "Fin del 6to plot"

echo "Incio de plot Totales"
cd plot7
./plotTotales1.sh
echo "Directorio 7"
cd ..
echo "Fin del 7mo plot"

echo "Continuacion de plot Totales"
cd plot8
./plotTotales2.sh
echo "Directorio 8"
cd ..
echo "Fin del 8vo plot"



#rm *.dat
#echo "Archivos .dat eliminados"
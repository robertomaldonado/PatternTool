#!/bin/sh

#INICIO PLOTEO DEL PRIMER VECTOR

#####PLOTEO GRUPO1

    #Eliminar .dat existentes
    rm *.dat
    echo "Archivos eliminados"

    #Obtener las estadisticas promedio
    ./extractAverageData1.sh
    #obtener estadiscas del autor desconocido
    ./extractUnknownData1.sh

    #Generar graficas con barras de error
    echo "Graficacion de resultados"
    ./plotHistogram1.sh

#####PLOTEO GRUPO2

    #Eliminar .dat existentes
    rm *.dat
    echo "Archivos eliminados"

    #Obtener las estadisticas promedio
    ./extractAverageData2.sh
    #obtener estadiscas del autor desconocido
    ./extractUnknownData2.sh

    #Generar graficas con barras de error
    echo "Graficacion de resultados"
    ./plotHistogram2.sh

#####PLOTEO GRUPO3

   #Eliminar .dat existentes
    rm *.dat
    echo "Archivos eliminados"

    #Obtener las estadisticas promedio
    ./extractAverageData3.sh
    #obtener estadiscas del autor desconocido
    ./extractUnknownData3.sh

    #Generar graficas con barras de error
    echo "Graficacion de resultados"
    ./plotHistogram3.sh

#####PLOTEO GRUPO4

    #Eliminar .dat existentes
    rm *.dat
    echo "Archivos eliminados"

    #Obtener las estadisticas promedio
    ./extractAverageData4.sh
    #obtener estadiscas del autor desconocido
    ./extractUnknownData4.sh

    #Generar graficas con barras de error
    echo "Graficacion de resultados"
    ./plotHistogram4.sh

#####PLOTEO GRUPO NUMERICO

    #Eliminar .dat existentes
    rm *.dat
    echo "Archivos eliminados"

    #Obtener las estadisticas promedio
    ./extractAverageDataNum.sh
    #obtener estadiscas del autor desconocido
    ./extractUnknownDataNum.sh

    #Generar graficas con barras de error
    echo "Graficacion de resultados"
    ./plotHistogramNum.sh

#####PLOTEO GRUPO TILDES

    #Eliminar .dat existentes
    rm *.dat
    echo "Archivos eliminados"

    #Obtener las estadisticas promedio
    ./extractAverageDataAccented.sh
    #obtener estadiscas del autor desconocido
    ./extractUnknownDataAccented.sh

    #Generar graficas con barras de error
    echo "Graficacion de resultados"
    ./plotHistogramAccented.sh

#####PLOTEO GRUPO PROMEDIOS GRUPO 1

    #Eliminar .dat existentes
    rm *.dat
    echo "Archivos eliminados"

    #Obtener las estadisticas promedio
    ./extractAverageDataAvg1.sh
    #obtener estadiscas del autor desconocido
    ./extractUnknownDataAvg1.sh

    #Generar graficas con barras de error
    echo "Graficacion de resultados"
    ./plotHistogramAvg1.sh

#####PLOTEO GRUPO PROMEDIOS GRUPO 1

    #Eliminar .dat existentes
    rm *.dat
    echo "Archivos eliminados"

    #Obtener las estadisticas promedio
    ./extractAverageDataAvg2.sh
    #obtener estadiscas del autor desconocido
    ./extractUnknownDataAvg2.sh

    #Generar graficas con barras de error
    echo "Graficacion de resultados"
    ./plotHistogramAvg2.sh

#####PLOTEO GRUPO TOTALES GRUPO 1

    #Eliminar .dat existentes
    rm *.dat
    echo "Archivos eliminados"

    #Obtener las estadisticas promedio
    ./extractAverageDataTot1.sh
    #obtener estadiscas del autor desconocido
    ./extractUnknownDataTot1.sh

    #Generar graficas con barras de error
    echo "Graficacion de resultados"
    ./plotHistogramTot1.sh

#####PLOTEO GRUPO TOTALES GRUPO 2

    #Eliminar .dat existentes
    rm *.dat
    echo "Archivos eliminados"

    #Obtener las estadisticas promedio
    ./extractAverageDataTot2.sh
    #obtener estadiscas del autor desconocido
    ./extractUnknownDataTot2.sh

    #Generar graficas con barras de error
    echo "Graficacion de resultados"
    ./plotHistogramTot2.sh

#####PLOTEO GRUPO TOTALES GRUPO 2

    #Eliminar .dat existentes
    rm *.dat
    echo "Archivos eliminados"

    #Obtener las estadisticas promedio
    ./extractAverageDataGreet.sh
    #obtener estadiscas del autor desconocido
    ./extractUnknownDataGreet.sh

    #Generar graficas con barras de error
    echo "Graficacion de resultados"
    ./plotHistogramGreet.sh

    #Eliminar .dat existentes
    rm *.dat
    echo "Archivos eliminados"

#!/bin/sh
#inputs  1 output name, 2 PF file name, 3 MLWDF file name, 4 EXP/PF file name, 5 Title, 6 x label, 7 Y label
filename=.temp3.data

echo "set terminal postscript eps enhanced solid color \"FreeSans\" 16" > $filename

 #echo "set terminal jpeg size 1024,768;" > $filename
echo "set output '../syntactical/puntuationAndExpresion.eps';">> $filename

echo "set termoption dashed" >> $filename

echo "set style line 1 lt 1 lc 3 lw 3 " >> $filename # blue = lc 3
echo "set style line 2 lt 2 lc 1 lw 3 " >> $filename # red = lc 1
echo "set style line 3 lt 3 lc 4 lw 3 " >> $filename
echo "set style line 4 lt 3 lc 5 lw 3 " >> $filename
echo "set style line 5 lt 8 lc 7 lw 3 " >> $filename #
echo "set style line 6 lt 8 lc 6 lw 3 " >> $filename #
echo "set style line 7 lt 8 lc 2 lw 3 " >> $filename #

echo "set style  data linespoints" >> $filename

echo "set xtics font \"FreeSans,16\"" >> $filename
#echo "set xtics(1) font \"FreeSans,20\"" >> $filename
echo "set xtics('PPD' 1 , 'PCN' 2, 'PCA' 3 , 'PSC' 4, 'EEO' 5 , 'EEC' 6, 'EQO' 7 , 'EQC' 8 ) font \"FreeSans,16\"" >> $filename
echo "set ytics font \"FreeSans,16\"" >> $filename

echo "set grid" >> $filename
echo "set boxwidth 0.90 relative" >> $filename

 #echo "set boxwidth 0.5 absolute" >> $filename
 echo "set style fill solid 1.0 noborder" >> $filename
 #echo "set key width 4 height 1 box enhanced inside left" >> $filename
 echo "set key width 1 height 1 box enhanced inside top right" >> $filename
 echo "set xlabel \"Parameters\" font \"FreeSans,18\"" >> $filename
 echo "set ylabel \"Repetition Index \" font \"FreeSans,18\"" >> $filename

 echo "plot  'estadisticaGlobalIndiv1.dat' ls 1 title 'Author1', 'estadisticaGlobalIndiv2.dat' ls 2 title 'Author2 T1','estadisticaGlobalIndiv3.dat'  ls 4 title 'Author2 T2', 'estadisticaGlobalIndiv4.dat' ls 3 title 'Author2 T3', 'estadisticaGlobalIndiv5.dat' ls 5 title 'Author2 T4','estadisticaGlobalIndiv6.dat' ls 7 title 'Author2 T5','estadisticaGlobal.dat' ls 6 title 'Average A2' " >> $filename

gnuplot $filename
rm -Rf $filename

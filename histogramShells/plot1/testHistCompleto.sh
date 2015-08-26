#!/bin/sh
#inputs  1 output name, 2 PF file name, 3 MLWDF file name, 4 EXP/PF file name, 5 Title, 6 x label, 7 Y label
filename=.temp3.data

echo "set terminal postscript eps enhanced solid color \"FreeSans\" 16" > $filename

 #echo "set terminal jpeg size 1024,768;" > $filename
echo "set output 'testCompleto.eps';">> $filename

echo "set termoption dashed" >> $filename

echo "set style line 1 lt 1 lc 3 lw 3 " >> $filename # blue = lc 3
echo "set style line 2 lt 2 lc 1 lw 3 " >> $filename # red = lc 1
echo "set style line 3 lt 3 lc 4 lw 3 " >> $filename
echo "set style line 4 lt 3 lc 5 lw 3 " >> $filename
echo "set style line 5 lt 8 lc 7 lw 3 " >> $filename

echo "set style histogram errorbars gap 1 lw 1 " >> $filename
echo "set style data histograms" >> $filename

echo "set xtics font \"FreeSans,16\"" >> $filename
#echo "set xtics(1) font \"FreeSans,20\"" >> $filename
echo "set xtics('PPD' 0 , 'PCN' 1, 'PCA' 2 , 'PSC' 3, 'EEO' 4, 'EEC' 5, 'EQO' 6 , 'EQC' 7 ) font \"FreeSans,16\"" >> $filename
echo "set ytics font \"FreeSans,16\"" >> $filename

echo "set grid" >> $filename
echo "set boxwidth 0.90 relative" >> $filename

 #echo "set boxwidth 0.5 absolute" >> $filename
 echo "set style fill solid 1.0 noborder" >> $filename
 #echo "set key width 4 height 1 box enhanced inside left" >> $filename
 echo "set key width 1 height 1 box enhanced inside top right" >> $filename
 echo "set xlabel \"Parameters\" font \"FreeSans,18\"" >> $filename
 echo "set ylabel \"Repetition Index \" font \"FreeSans,18\"" >> $filename

echo "plot  'estadisticaGlobalIndiv1.dat' ls 1 title 'Author Desconocido', 'estadisticaGlobalIndiv2.dat' ls 2 title 'Author2 T1','estadisticaGlobalIndiv3.dat'  ls 3 title 'Author2 T2', 'estadisticaGlobalIndiv4.dat' ls 4 title 'Author2 T3','estadisticaGlobal.dat' ls 5 title 'Average A2' " >> $filename

gnuplot $filename
rm -Rf $filename

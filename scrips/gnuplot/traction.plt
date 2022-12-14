set xrange [0:140]
set xlabel 'Скорость, км/ч'
set yrange [0:450]
set ylabel 'Сила тяги, кН'

set grid

set encoding utf8
set tics font "Helvetica,12"
set xlabel font "Helvetica,12"
set ylabel font "Helvetica,12"

set style line 1 lt 1 lw 1 lc rgb '#4682b4' pt 3
set style line 2 lt 1 lw 2 lc rgb '#aa0000' pt 3

plot	'zone1.csv' using 1:2  w l ls 1 ti 'ЭП1м тяговая характеристика', \
		'zone2.csv' using 1:2  w l ls 1 noti, \
		'zone3.csv' using 1:2  w l ls 1 noti, \
		'zone4.csv' using 1:2  w l ls 1 noti, \
		'up-limit.csv' using 1:2  w l ls 1 noti, \
		'reg_data_15-12-2022_00-09-54.txt' using 2:4 w l ls 2 ti 'ЭП1м RRS измерение тяги'
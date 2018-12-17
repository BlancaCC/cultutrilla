nombre_archivo=`date +%Y-%j-%T`
ps -f > $nombre_archivo
echo Mi pid es $$>> ~/practica_4/$nombre_archivo
/usr/games/xcowsay Hola,  ha pasado un minuto y el crontab sigue dando la vara


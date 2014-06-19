if [ ! -f metacgl.lst ]  
then 
	touch  metacgl.lst
	md5sum  metacgl.lst > md5file_npw.md5
fi 
 
if [ ! -f md5file_npw.md5 ]  
then 
	md5sum  metacgl.lst > md5file_npw.md5
fi 
 
t=$(date '+%s') 
while [[ $(($(date '+%s') - $t)) -le 10800 ]]  
do 
  wget -c http://bossa.pl/pub/ciagle/mstock/metacgl.lst -N 2>/dev/null 
  sleep 5s 
  md5sum -c  md5file_npw.md5
  wynik=$? 
  echo $wynik 
  if [  $wynik -eq 1 ] 
  then 
    echo "----- Plik jest nowy  ---------" 
    md5sum  metacgl.lst >  md5file_npw.md5
    tar -zcvf  ./arch/arch$(date '+%Y_%m_%d_%H%M%S').tar.gz metacgl.lst
    cp  metacgl.lst  dane_npw.txt 
    break 
  fi 
done 

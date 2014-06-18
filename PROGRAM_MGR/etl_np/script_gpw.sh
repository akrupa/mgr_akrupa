if [ ! -f sesjacgl.prn ]  
then 
	touch  sesjacgl.prn
	md5sum  sesjacgl.prn > md5file_gpw.md5
fi 
 
if [ ! -f md5file_gpw.md5 ]  
then 
	md5sum  sesjacgl.prn > md5file_gpw.md5
fi 
 
t=$(date '+%s') 
while [[ $(($(date '+%s') - $t)) -le 10800 ]]  
do 
  wget -c http://bossa.pl/pub/ciagle/mstock/sesjacgl/sesjacgl.prn -N 2>/dev/null 
  sleep 5s 
  md5sum -c  md5file_gpw.md5
  wynik=$? 
  echo $wynik 
  if [  $wynik -eq 1 ] 
  then 
    echo "----- Plik jest nowy  ---------" 
    md5sum  sesjacgl.prn >  md5file_gpw.md5
    tar -zcvf  ./arch/arch$(date '+%Y_%m_%d_%H%M%S').tar.gz sesjacgl.prn
    cp  sesjacgl.prn  dane_gpw.txt 
    break 
  fi 
done 

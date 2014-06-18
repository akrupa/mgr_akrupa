# skrypt do ściągania danych giełdowych z GPW
# dane pochodzą ze strony bossa.pl/notowania/metastock 
#(notowania ciągłe , dane bieżące, plik sesjacgl.prn)

if [ ! -f sesjacgl.prn ] 
then
	touch sesjacgl.prn
	md5sum sesjacgl.prn > md5file.md5
fi

if [ ! -f md5file.md5 ] 
then
	md5sum sesjacgl.prn > md5file.md5
fi

t=$(date '+%s')
while [[ $(($(date '+%s') - $t)) -le 10800 ]] 
do
  # ściągamy plik jeśli jest nowszy niż uprzednio ściągnięty
  wget http://bossa.pl/pub/ciagle/mstock/sesjacgl/sesjacgl.prn -N 2>/dev/null
  sleep 5s
  # Jeżeli suma kontrolna się zmieni, to znaczy, że plik pod w/w adresem się zmienił
  # i zostanie wykonany warunek
  # Jeżeli w zmiennej $? będzi 1, to plik został zmienony
  md5sum -c md5file.md5 
  wynik=$?
  echo $wynik
  if [  $wynik -eq 1 ]
  then
    echo "----- Plik jest nowy  ---------"
    # Tworzony jest plik sesja.txt, który jest wykorzystywany do ładowania danych do bazy.
    md5sum sesjacgl.prn > md5file.md5
    cp ./sesjacgl.prn ./copySesjacgl.prn
    tar -zcvf  ./arch_gpw/arch$(date '+%Y_%m_%d_%H%M%S').tar.gz sesjacgl.prn
    cp  sesjacgl.prn sesja.txt
    break
  fi
done



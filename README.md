Krav för att köra:
G++ (körde med 13.3.0-6)
C++ 17 eller senare
Bygga: (Linux) skriv I src mappen: g++ ·cc -o out    →tryck enter
Sedan skriv:   ./out

Appanvändning:
Följande kommandon är tillgängliga:

**last-event <sensorId>**   (exempel: last-event 2, printar sista eventet för given sensor)
**tick <n> **                       (exempel: tick 10, scannar alla sensorer, flyttar eventpekare från kö till logg)
**printlog**			  (exempel: printlog, skriver ut alla events)

**selectionsort** “timestamp, reading, id” (exempel: selectionsort reading, sorterar alla events efter reading)

**insertionsort “timestamp, reading, id” **(exempel: som ovan fast annan sorteringalgoritm)

**find <sensorId>** (exempel: find 0, printar alla events för given sensor)

**check-alarms** (exempel: check-alarms, kollar om det finns aktiva larm)

**help** (exempel: help, listar alla kommandon)

**exit** (exempel: exit, avslutar programmet)

3 hårdkodade sensorer (motion, temperature och humidity)
Humidity min threshold: 10, max: 60
Temperature min: 5 max: 25
Motion ger bara 1 vid detection och 0 vid ingen detection


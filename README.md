# VU OOP
## Naujų tipų kūrimas ir jų naudojimas
## Intro
Užduotis atlikta Objektinio programavimo kursui (VU Informacinių sistemų inžinerija).
[UŽDUOTIES PUSLAPIS](https://github.com/objprog/paskaitos2019/wiki/3-oji-u%C5%BEduotis)

## Versijos
### v1.1

Nuo struktūrų išemigruota prie klasių. Sukurti GET'eriai bei SET'eriai, pagalbiniu darbui su klasių objektais. Atitinkamai sutvarkytos ir perdarytos funkcijos. Atlikti realizacijos spartos testai su vector tipo konteineriu. Atlikta analizė su flag'ais: O1, O2, O3. 

#### Realizacijos spartos testai

10 studentų:

Klasės
```
List generation : 0.0009937 s
Sorting students : 0 s
Grouping students : 0 s
Outputting students to files : 0.0009602 s
```

Struktūros
```
[Nuotrauka](https://imgur.com/GflAb6K.png)
```

1000 studentų:

Klasės
```
List generation : 0.0030203 s
Sorting students : 0.001005 s
Grouping students : 0.0498661 s
Outputting students to files : 0.0050058 s
```

Struktūros
```
[Nuotrauka](https://imgur.com/RquAXVO.png)
```

10000 studentų:

Klasės
```
List generation : 0.0279438 s
Sorting students : 0.0178996 s
Grouping students : 5.04227 s
Outputting students to files : 0.0359407 s
```

Struktūros
```
[Nuotrauka](https://imgur.com/0jEeez4.png)
```

#### Analizė su flag'ais (10000 studentų)

O1
```
List generation : 0.0772052 s
Sorting students : 0.111865 s
Grouping students : 17.0848 s
Outputting students to files : 0.0966831 s
```
O2
```
List generation : 0.0852258 s
Sorting students : 0.102242 s
Grouping students : 16.3649 s
Outputting students to files : 0.0646554 s
```
O3
```
List generation : 0.0881155 s
Sorting students : 0.109506 s
Grouping students : 16.2665 s
Outputting students to files : 0.0643469 s
```


## Duomenų apdorojimas (Ankstesnė užduotis)
## Intro
Užduotis atlikta Objektinio programavimo kursui (VU Informacinių sistemų inžinerija).
[UŽDUOTIES PUSLAPIS](https://github.com/objprog/paskaitos2019/wiki/2-oji-u%C5%BEduotis)

## Versijos
### v0.1

Programa nuskaito studento V/P (input), namų darbų bei egzamino rezultatus. Rezultatas išvedamas į konsolę. Vėliau panaudotos dvi skirtingos konteinerių rūšys: C masyvas ir vektorius. Juose saugomi namų darbų rezultatai. Pridėta atsitiktinių pažymių generacija.

### v0.2

Duomenų nuskaitymas iš ```kursiokai.txt``` failo. Sukurtas sulygiuotų rezultatų išvedimas į konsolę surikiavus studentus.

### v0.3

Iškeltos funkcijos bei struktūros į atskirus header failus ```/headers/``` aplanke. Panaudoti ```exception handling``` metodai, kad apsaugoti programą nuo neveikimo dėl nesamo duomenų nuskaitymo failo.

### v0.4

#### Programos greičio spartos analizė
- **10 studentų generacija:**
    - [Nuotrauka](https://imgur.com/GflAb6K.png)
- **100 studentų generacija:**
    - [Nuotrauka](https://imgur.com/mxKBVGF.png)
    - [Nuotrauka](https://imgur.com/xZqENN0.png)
- **1000 studentų generacija:**
    - [Nuotrauka](https://imgur.com/RquAXVO.png)
    - [Nuotrauka](https://imgur.com/3GHTgBF.png)
- **10000 studentų generacija:**
    - [Nuotrauka](https://imgur.com/0jEeez4.png)
    - [Nuotrauka](https://imgur.com/WYi0t6p.png)
- **Maksimali studentų generacija (29000 studentų):**
    - [Nuotrauka](https://imgur.com/xJ9jNFd.png)
    - Rezultatas nebuvo išvedamas į konsolę, nes per didelis studentų skaičius priverstų programą sunaudoti per didelę dalį atminties bei gali priversti nutraukti tolimesnį programos vykdymą dėl apkrovos procesoriui.
- **CPU apkrova, kai studentų generuojama daugiau, negu 29000:**
    - [Nuotrauka](https://imgur.com/AOXIeAf.png)

### v0.5

#### Programos testavimas naudojant skirtingus STL konteinerius
- [Vector](https://imgur.com/skcD1pY.png)
- [List](https://imgur.com/D1COYZj.png)
- [Deque](https://imgur.com/6vJbsoB.png)

### v1.0 Final version

#### The two strategy comparison (speed test):

**VECTORS:**
- 1st WAY
```
Data input : 12.2456 s
List generation : 2.30376 s
Output file creation : 31.3149 s
```
- 2nd WAY
```
Data input : 23.1446 s
List generation : 2.9846 s
Output file creation : 25.7201 s
```

**DEQUE:**
- 1st WAY
```
Data input : 7.1919 s
List generation : 9.05115 s
Output file creation : 59.7953 s
```
- 2nd WAY
```
Data input : 8.54892 s
List generation : 8.01951 s
Output file creation : 23.987 s
```

**LIST:**
- 1st WAY
```
Data input : 6.75256 s
List generation : 2.51547 s
Output file creation : 30.6666 s
```
- 2nd WAY
```
Data input : 23.9859 s
List generation : 4.11313 s
Output file creation : 19.7126 s
```


### Kaip paleisti programą?

Jeigu naudojate CLion, tai paleisti programą galima su CMake pagalba. O jeigu norite paleisti programą su terminalu (CMD prompt), tai šitas kodas tai padarys:
```g++ -o main main.cpp headers/studs.h headers/student.h headers/main.h headers/functions.cpp```
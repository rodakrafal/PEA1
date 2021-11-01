# PEA1

## Project written as a part of PEA classes - effective design of algorithms

The main premise of the project is to get familiar with the traveling salesman problem. We had to write, implement and analyze the efficiency of three algorithms:
- Branch and bound
- Brute force
- Dynamic programming

The exact task can be found here [unfortunately it is written entirely in polish :speak_no_evil:](http://jaroslaw.mierzwa.staff.iiar.pwr.wroc.pl/pea-lab/pea_proj1_jm_2021_v1.pdf)


## Table of contents

* [Details](#Details)
* [Algoriths](#Complition_of_the_algorithms)
* [Literature](#Used_literature)


## Details

Project was written on linux (WLS Ubntu version 20.04). To run this project, download it locally and execute it. Additonaly you can run this project using valgrind.

Additonaly you can run this project using Makefile comments or valgrim commends like:

```
$ make run 
$ make valgrind 
$ make valgrindleak
```

Used Tech | Quick description
------------ | -------------
Valgrind | checks leaks
STl | already created structures
CMake Tools| for automatization 


## Complition of the algorithms 

- [X] Brute force without external librariesclea
- [X] Brute force
- [ ] Branch and bound
- [X] Dynamic programming


### Used literature 

1. D.E. Goldberg, Algorytmy genetyczne i ich zastosowania, Warszawa, WNT 1998.
2. Z Michalewicz, Algorytmy genetyczne + struktury danych = programy ewolucyjne,Warszawa,
WNT 1996.
3. Z. Michalewicz, D.B. Fogel, Jak to rozwiązać, czyli nowoczesna heurystyka, WNT 2006.
4. V. Cerny, A thermodynamical approach to the travelling salesman problem: an efficient
simulation algorithm, Journal of Optimization Theory and Applications, 45: 41-51, 1985.


(c) Rafał Rodak

Licensed under the [MIT License](LICENSE)
# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.0)

# Notre projet est étiqueté bataille navale
project(bataillenavale)

# Crée des variables avec les fichiers à compiler
set(SRCS
    main.c
    cellule.c
    bateau.c
    flotte.c
    vue.c
    method.c
    )
    
set(HEADERS
    define.h
    cellule.h
    bateau.h
    flotte.h
    vue.h
    method.h
    )

# On indique que l'on veut un exécutable "bataille navale" compilé à partir des fichiers décrits par les variables SRCS et HEADERS
add_executable(bataillenavale ${SRCS} ${HEADERS})

target_link_librairies(main)
install (TARGETS main DESTINATION bin)

include (CPack)

cmake_minimum_required(VERSION 2.6) #LA VERSION MINIMUM

project(Indie) #NOM DU PROJET

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE}) #LA Où ON VEUT SORTIR LE BINAIRE (facultatif)

#Déclaration des DOSSIER CONTENANT LES FICHIERS
file(
    GLOB_RECURSE
    sources_files #Nom de la Variable contenant les Dossiers
    src/* #Dossier contenant des fichiers( "*" pour dire tous les fichiers)
    # src/olivier/* #Autre Dossier contenant d'autres fichiers
)

add_executable(
    bomberman #Nom de l'executable
    ${sources_files} #Variable contenant les Dossiers qui eux contiennes des fichiers
)
target_compile_options (bomberman PRIVATE -std=c++11)
target_link_libraries (bomberman -lIrrlicht -lGL -lXxf86vm -lXext -lX11)
# En cas de Modifications du fichier Voici quelques exemples d'informations qui ne doivent pas figurer dans le fichier:
#  -le chemin vers votre compilateur ou tout autre utilitaire participant à la compilation ;
#  -le chemin vers une bibliothèque tierce ;
#  -les options de compilation propres au système (optimisation pour une architecture particulière) ou au cas d'utilisation (niveau d'optimisation, présence des symboles de débogage ;
#  -le niveau de verbosité des scripts de compilation générés ;
# etc.
#Tous ces paramètres personnels doivent être définis ailleurs : dans le fichier CMakeCache.txt.
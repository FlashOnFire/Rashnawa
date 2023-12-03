# Rashnawa

Rashnawa est un jeu 2D plateformer écrit en C++ axé sur l'exploration. Il a été créé dans le cadre d'un projet d'études en 2e année à Polytech Lyon.

## Arborescence
Le repo se divise en plusieurs dossiers correspondant aux différentes parties du projet :
- ``assets`` contient les fichiers externes nécéssaires au fonctionnement du jeu (images, musiques, maps)
- ``fmod_project`` contient le projet FMOD complet du jeu (pour les musiques)
- ``src`` contient les fichiers sources du jeu
- ``inc`` contient les headers des bibliothèques utilisées
- ``lib_linux`` et ``lib_windows`` contiennent respectivement les bibliothèques compilées pour windows et linux (pour la compilation)
- ``supress.txt`` est le fichier de suppression valgrind pour retirer les faux positifs (ceux liés au driver nvidia sous linux par exemple)

## Compilation
Le projet a été créé avec CMake pour faciliter la compilation

## Auteurs
Ce projet a été mené par 3 étudiants en 2e année d'études à Polytech Lyon
- Guillaume Calderon
- Thibaut Laracine
- Emmanuel Luquin

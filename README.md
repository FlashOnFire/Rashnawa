# Rashnawa

Rashnawa est un jeu 2D plateformer écrit en C++ axé sur l'exploration. Il a été créé dans le cadre de l'UE LIFAPCD au
printemps 2024

## Histoire

// TODO

## Fonctionnalités

- Déplacements (droite, gauche, saut, dash dans plusieurs directions)
- Attaque avec de multiples armes
- Plusieurs monstres différents
- Plusieurs salles
- Plusieurs zones
- Un système de sauvegarde et de progression
- Options complètes (son et volume, contrôles, graphismes)
- Barre de vie
- Animations
- Effets visuels

## Arborescence

Le repo se divise en plusieurs dossiers correspondant aux différentes parties du projet :

- ``assets`` contient les fichiers externes nécéssaires au fonctionnement du jeu (images, musiques, maps)
- ``fmod_project`` contient le projet FMOD complet du jeu (pour les musiques)
- ``src`` contient les fichiers sources du jeu
- ``include`` contient les headers des bibliothèques utilisées
- ``lib_linux`` et ``lib_windows`` contiennent respectivement les bibliothèques compilées pour windows et linux (pour la
  compilation)
- ``supress.txt`` est le fichier de suppression valgrind pour retirer les faux positifs (ceux liés au driver nvidia sous
  linux par exemple)

Le dossier assets contient plusieurs sous-dossiers :

- ``assets/animations`` contient les fichiers représentant les différentes animations
  (//TODO expliquer qu'est ce qu'il y a à chaque ligne)
- ``assets/audio`` contient les assets audio
- ``assets/fonts`` contient les polices utilisées pour le texte du jeu
- //TODO finir de dire tout ce qu'il y a

## Compilation

Le projet a été créé avec CMake pour faciliter la compilation.

### Sous Linux :

```bash
cmake -B cmake-build-release
cd cmake-build-release
make
```

Et ``./Rashnawa`` pour lancer le programme

### Sous Windows :

```bash
cmake -G "MinGW Makefiles" -B cmake-build-release
cd cmake-build-release
make
```

Et ``Rashnawa.exe`` pour lancer le programme

Suivant les installations, il faudra peut être adapter légèrement les commandes (par exemple utiliser ``mingw32-make`` au lieu de ``make``)

> Nous avons fait au mieux pour inclure les shared libraries nécéssaires au fonctionnement du programme (fichiers .dll)
> dans le dossier de build. Les dll liés aux bibliothèques que nous utilisons sont correctement copiés mais il se peut que
> ceux de la lib C++ ne se copient pas correctement si vous avez un compilateur différent du notre (MinGW). Dans ce cas,
> il faudra copier manuellement les dlls correspondants (trouvables dans le dossier de votre compilateur) dans le dossier
> de build avant de lancer le programme. Si le programme ne trouve pas les dlls nécéssaires à son fonctionnement dans le
> même dossier que le .exe, il affichera un message d'erreur puis se fermera.

> Nous avons dû désactiver les messages d'erreur sous windows pour éviter d'afficher une console derrière le jeu. Si la
> fenêtre s'ouvre puis se ferme presque instantanément sans message d'erreur, il est probable que vous n'ayez pas installé
> de drivers graphiques et que le jeu n'arrive pas à charger les textures (machine virtuelle ?)

## Auteurs

Ce projet a été mené par 3 étudiants en 2e année d'études à Polytech Lyon

- Guillaume CALDERON (p2205143)
- Thibaut LARACINE (pXXXXXX)
- Emmanuel LUQUIN (pXXXXXX)
Projet de Anand Ballou et Alexandre Poupeau.

1) HOW TO : Compiler le projet.

Se rendre dans le dossier build/.
Eventuellement lancer la commande cmake ..
Executer la commande make.
(Ne pas hésiter à lancer la commande make clean en cas de bug)

2) HOW TO : Lancer le programme principal.

S'assurer d'avoir compilé le projet.
Depuis le dossier build/, éxécuter la command suivante ./src/Main_Visualization
avec comme argument le modèle choisi.
Exemple : "./src/Main_Visualization Gerstner" ou "./src/Main_Visualization Philips"

Informations pour aller plus loin :
  Dans le fichier src/main.cxx :
  Les paramètres suivants peuvent être modifiés pour changer l'affichage:
    nx, ny, length, width
  Les paramètres suivants peuvent être modifiés pour changer l'allure des vagues:
    nbWaves, windDirection, averageAlignment, intensite, longueurOnde, hauteurVague
  Se déplacer pendant la simulation pour mieux apprécier les vagues :
    Déplacer la sourie pour l'orientation.
    D droite, A gauche, S derrière, W devant.

3) HOW TO : Lancer les tests.

Lancer l'ensemble des tests d'un coup :
  S'assurer d'avoir compilé le projet.
  Lancer au choix les commandes suivantes (depuis le dossier build/):
    - make test ou ctest (identique)
    - ctest -T memcheck (vérifie les fuites de mémoire de tous les fichiers de test)

Pour lancer les tests un par un :
  Se rendre dans build/test/.
  Lancer les tests avec la commande suivante ./{nom_du_fichier_à_tester}_test.
  Exemple : "valgrind ./Dvector_test" ou "./GerstnerWaveModel_test".
  Tous les fichiers terminant avec un "_test" sont des fichiers tests
  conçus par nos soins.

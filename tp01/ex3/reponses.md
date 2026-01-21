# Expliquez la différence entre phase de build (compilation) et phase de link (édition des liens).

Phase de build / compilation
Chaque fichier source (.cpp) est traité indépendamment.

Étapes :
Préprocessing (`#include`, `#define`, etc.)
Compilation → transformation en code objet (.o)

Le compilateur vérifie :
La syntaxe
Les types
La visibilité des symboles

Phase de link (édition des liens)
Le linker assemble tous les fichiers objets pour produire l’exécutable.

Il vérifie :
Que chaque fonction utilisée a une définition
Que les symboles sont bien résolus entre fichiers


# En quoi consiste la précompilation et à quel moment est-elle effectuée ?

La précompilation est une étape avant la compilation, réalisée par le préprocesseur.

Elle consiste à :
Remplacer les `#include` par le contenu des fichiers inclus
Évaluer les `#define`
Supprimer les commentaires
Gérer les directives conditionnelles (#ifdef)
Elle a lieu avant la compilation proprement dite.


# Que signifient les messages suivants ?

## a. error: 'qqchose' was not declared in this scope
Signifie que le compilateur ne connaît pas le symbole `qqchose` à l’endroit où il est utilisé.

Causes possibles :
Variable ou fonction non déclarée
Header non inclus
Mauvais namespace

C'est une erreur de compilation

## b. error: 'qqchose' is not a member of 'std'
Signifie que qqchose n’existe pas dans l’espace de noms std.

Causes possibles :
Mauvais nom (`std::sting` au lieu de `std::string`)
`#include` manquant
Confusion avec une fonction non standard

C'est une erreur de compilation

## Ces erreurs se produisent-elles pendant la phase de build ou de link ?
Ces deux erreurs apparaissent pendant la phase de build (compilation)
Le linker n’est jamais atteint si la compilation échoue

## Que fait exactement l'instruction préprocesseur #include et pourquoi permet-elle généralement de résoudre ce type de problème ?
Il copie-colle littéralement le contenu du fichier inclus à l’endroit de la directive avant la compilation

Pourquoi ça résout ces erreurs ? Parce que :
Les déclarations deviennent visibles
Le compilateur connaît les types, fonctions et classes
Les symboles sont reconnus dans le bon namespace
Sans `#include`, le compilateur ne sait pas que le symbole existe, même s’il sera défini plus tard.

# Compilez maintenant le programme complet (avec les modules main et utils).  

## Quelle est l'erreur qui s'affiche ? S'agit-il d'une erreur de build ou de link ?  
`g++ -std=c++17 -o bonjour main.cpp utils.cpp && ./bonjour
/usr/bin/ld : /tmp/ccS6EiGF.o : dans la fonction « print_bye() » :
utils.cpp:(.text+0x0) : définitions multiples de « print_bye() »; /tmp/cc8OEKxU.o:main.cpp:(.text+0x0) : défini pour la première fois ici
collect2: error: ld returned 1 exit status`

Il s'agit ici d'une erreur de link

## Pourquoi se produit-elle ?  
Dans notre cas, on a main.cpp et utils.cpp qui déclarent `#include "utils.hpp"`. De fait, la fonction `print_bye()` est vue (et définie) deux fois

## Que faudrait-il faire pour la résoudre ?
Pour résoudre cette erreur, il faudrait ajouter `inline` deva&nt notre `print_bye()`, car on définit ici une fonction dans notre header.

## Ajoutez le mot-clef `inline` devant la définition de la fonction `print_bye` dans [utils.hpp](ex3/utils.hpp). Que constatez-vous quand vous réessayez de compiler le programme ?  
Ça marche bien

# Selon-vous, quel est l'effet du mot-clef `inline` sur le linker ?
`inline` autorise plusieurs définitions identiques 
